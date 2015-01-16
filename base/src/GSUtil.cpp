#include <GameSparks/GSUtil.h>

#ifdef MARMALADE
#include "gsCPPBase/deps/hmac/hmac_sha2.h"
#else
#include <openssl/hmac.h>
#endif

using namespace GameSparks::Util;

static const gsstl::string base64_chars =
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz"
			"0123456789+/";


static inline bool is_base64(unsigned char c) {
	return (isalnum(c) || (c == '+') || (c == '/'));
}

gsstl::string GameSparks::Util::base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len) {
	gsstl::string ret;
	int i = 0;
	int j = 0;
	unsigned char char_array_3[3];
	unsigned char char_array_4[4];

	while (in_len--) {
		char_array_3[i++] = *(bytes_to_encode++);
		if (i == 3) {
			char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
			char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
			char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
			char_array_4[3] = char_array_3[2] & 0x3f;

			for (i = 0; (i < 4); i++)
				ret += base64_chars[char_array_4[i]];
			i = 0;
		}
	}

	if (i)
	{
		for (j = i; j < 3; j++)
			char_array_3[j] = '\0';

		char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
		char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
		char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
		char_array_4[3] = char_array_3[2] & 0x3f;

		for (j = 0; (j < i + 1); j++)
			ret += base64_chars[char_array_4[j]];

		while ((i++ < 3))
			ret += '=';

	}

	return ret;

}

gsstl::string GameSparks::Util::base64_decode(gsstl::string const& encoded_string) {
	int in_len = encoded_string.size();
	int i = 0;
	int j = 0;
	int in_ = 0;
	unsigned char char_array_4[4], char_array_3[3];
	gsstl::string ret;

	while (in_len-- && (encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
		char_array_4[i++] = encoded_string[in_]; in_++;
		if (i == 4) {
			for (i = 0; i < 4; i++)
				char_array_4[i] = base64_chars.find(char_array_4[i]);

			char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
			char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
			char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

			for (i = 0; (i < 3); i++)
				ret += char_array_3[i];
			i = 0;
		}
	}

	if (i) {
		for (j = i; j < 4; j++)
			char_array_4[j] = 0;

		for (j = 0; j < 4; j++)
			char_array_4[j] = base64_chars.find(char_array_4[j]);

		char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
		char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
		char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

		for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
	}

	return ret;
}

gsstl::string GameSparks::Util::getHMAC(gsstl::string nonce, gsstl::string appSecret)
{
	gsstl::string str = "";

#ifndef MARMALADE
	const unsigned int LEN = 64;
	unsigned int len = LEN;
	unsigned char result[LEN] = { 0 };

	HMAC_CTX ctx;
	HMAC_CTX_init(&ctx);

	HMAC_Init_ex(&ctx, appSecret.c_str(), appSecret.length(), EVP_sha256(), NULL);
	HMAC_Update(&ctx, (unsigned char*)nonce.c_str(), nonce.length());
	HMAC_Final(&ctx, result, &len);
	HMAC_CTX_cleanup(&ctx);

	str = base64_encode(result, len).c_str();

	return str;
#else
	char hmacDigest[SHA256_DIGEST_SIZE];
	memset(&hmacDigest, 0, SHA256_DIGEST_SIZE);

	hmac_sha256((const unsigned char*)appSecret.c_str(), appSecret.length(),
		(const unsigned char*)nonce.c_str(), nonce.length(),
		(unsigned char*)&hmacDigest, SHA256_DIGEST_SIZE);

	str = base64_encode((unsigned char*)hmacDigest, SHA256_DIGEST_SIZE);

#endif

	return str;
}

bool GameSparks::Util::shouldConnect()
{
	return true;
}

