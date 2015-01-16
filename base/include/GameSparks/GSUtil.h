#pragma once

#include <GameSparks/gsstl.h>

namespace GameSparks
{
	namespace Util
	{
		gsstl::string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len);
		gsstl::string base64_decode(gsstl::string const& encoded_string);
		gsstl::string getHMAC(gsstl::string nonce, gsstl::string appSecret);

		bool shouldConnect();
	}
}
