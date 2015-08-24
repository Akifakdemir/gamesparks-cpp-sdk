#include <GameSparks/IGSPlatform.h>

#if GS_TARGET_PLATFORM == GS_PLATFORM_ANDROID
#	include <sys/types.h>
#	include <unistd.h>
#	include <fstream>
#elif GS_TARGET_PLATFORM == GS_PLATFORM_WIN32
#	include <shlwapi.h>
#	pragma comment(lib,"shlwapi.lib")
#	pragma comment(lib, "Rpcrt4.lib")
#	include "shlobj.h"
#	include <Rpc.h>
#elif GS_TARGET_PLATFORM == GS_PLATFORM_MAC
#   include "TargetConditionals.h"
#   include <sys/stat.h> // for mkdir

	/* works like mkdir(1) used as "mkdir -p" */
	static void mkdirp(const char *dir) {
	    char tmp[PATH_MAX];
	    char *p = NULL;
	    size_t len;
	    
	    snprintf(tmp, sizeof(tmp),"%s",dir);
	    len = strlen(tmp);
	    if(tmp[len - 1] == '/')
	        tmp[len - 1] = 0;
	    for(p = tmp + 1; *p; p++)
	        if(*p == '/') {
	            *p = 0;
	            mkdir(tmp, S_IRWXU | S_IRWXG);
	            *p = '/';
	        }
	    mkdir(tmp, S_IRWXU | S_IRWXG);
	}

	gsstl::string get_osx_device_id();
#elif GS_TARGET_PLATFORM == GS_PLATFORM_IOS
    gsstl::string gs_ios_get_writeable_base_path();
    gsstl::string get_ios_device_id();
#else
//#	include <uuid/uuid.h>
#endif

namespace GameSparks { namespace Core {


// trim from start
static inline gsstl::string &ltrim(gsstl::string &s) {
        s.erase(s.begin(), gsstl::find_if(s.begin(), s.end(), gsstl::not1(gsstl::ptr_fun<int, int>(isspace))));
        return s;
}

// trim from end
static inline gsstl::string &rtrim(gsstl::string &s) {
        s.erase(gsstl::find_if(s.rbegin(), s.rend(), gsstl::not1(gsstl::ptr_fun<int, int>(isspace))).base(), s.end());
        return s;
}

// trim from both ends
static inline gsstl::string &trim(gsstl::string &s) {
        return ltrim(rtrim(s));
}

#if GS_TARGET_PLATFORM != GS_PLATFORM_MAC && GS_TARGET_PLATFORM != GS_PLATFORM_IOS
static gsstl::string generate_guid()
{
	gsstl::string ret = "NO-UUID-SUPPORT-FOR-THIS-PLATFORM";

	#ifdef WIN32
		UUID uuid;
		UuidCreate(&uuid);

		unsigned char * str;
		UuidToStringA(&uuid, &str);

		ret = gsstl::string((char*)str);

		RpcStringFreeA(&str);
	#elif defined(ANDROID)
		gsstl::ifstream ifs("/proc/sys/kernel/random/uuid");
		ifs >> ret;
	#endif
	/*#else
		uuid_t uuid;
		uuid_generate_random(uuid);
		char s[37];
		uuid_unparse(uuid, s);
		ret = s;
	#endif
		return ret;
	*/
	//assert(false);
	return trim(ret);
}
#endif


gsstl::string IGSPlatform::GetDeviceId() const
{
	static gsstl::string device_id;

	if (device_id.empty())
	{
		#if GS_TARGET_PLATFORM == GS_PLATFORM_MAC
			device_id = get_osx_device_id();
		#elif GS_TARGET_PLATFORM == GS_PLATFORM_IOS
			device_id = get_ios_device_id();
		#else
			device_id = generate_guid();
			StoreValue("device_id", device_id);
		#endif

		device_id = trim(device_id);
	}

	return device_id;
}



gsstl::string IGSPlatform::GetDeviceOS() const
{
	#if GS_TARGET_PLATFORM == GS_PLATFORM_MAC
		return "OSX";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_IOS
		return "IOS";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_ANDROID
		return "Android";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_WIN32
		return "W8";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_LINUX
		return "Linux";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_MARMALADE
		return "Marmelade";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_BADA
		return "Bada";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_BLACKBERRY
		return "Blackberry";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_NACL
		return "NaCl";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_EMSCRIPTEN
		return "emscripten";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_TIZEN
		return "Tizen";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_QT5
		return "QTS";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_WINRT
		return "W8";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_WP8
		return "WP8";
	#else
	#   error "Unsupported platform"
		return "Unknown";
	#endif
}


gsstl::string IGSPlatform::GetPlatform() const
{
	return GetDeviceOS();
}


void IGSPlatform::StoreValue(const gsstl::string& key, const gsstl::string& value) const
{
	// TODO: port to all the platforms
	FILE* f = fopen(ToWritableLocation(key).c_str(), "wb");
	assert(f);
	if (!f)
	{
    	DebugMsg("**** Failed to store value to '" + ToWritableLocation(key) + "'");
    	return;
	}
	size_t written = fwrite(value.c_str(), 1, value.size(), f);
    (void)(written);
    assert(written == value.size());
	fclose(f);
}


gsstl::string IGSPlatform::LoadValue(const gsstl::string& key) const
{
	// TODO: port to all the platforms
	FILE *f = fopen(ToWritableLocation(key).c_str(), "rb");
	
    if(!f)
    {
    	//DebugMsg("**** Failed to load value from '" + ToWritableLocation(key) + "'");
        return "";
    }
    
	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	if (fsize <= 0)
	{
		fclose(f);
		return "";
	}
	fseek(f, 0, SEEK_SET);
    gsstl::vector<char> bytes(static_cast<gsstl::vector<char>::size_type>(fsize));
	size_t read_bytes = fread(&bytes.front(), 1, fsize, f);
    (void)(read_bytes);
	assert(read_bytes == static_cast<size_t>(fsize));
	fclose(f);
	return gsstl::string( bytes.begin(), bytes.end() );
}


gsstl::string IGSPlatform::ToWritableLocation(gsstl::string desired_name) const
{
	desired_name = "gamesparks_" + desired_name;

	#if GS_TARGET_PLATFORM == GS_PLATFORM_MARMALADE || defined(GS_OVERRIDE_TOWRITABLELOCATION) // marmalade || windows; Note, that windows is for testing only. You should not put the files into the working directoy
    // http://docs.madewithmarmalade.com/display/MD/S3E+File+overview
	// This should work on marmalade
	return desired_name;

	#elif GS_TARGET_PLATFORM == GS_PLATFORM_WIN32

	static gsstl::string base_path;

	if (base_path.empty())
	{
		TCHAR szPath[MAX_PATH];
		if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, szPath)))
		{
			base_path = szPath;
		}
		else
		{
			DebugMsg("Failed to get CSIDL_APPDATA path.");
			base_path = "./";
			assert(false);
		}

		base_path += "\\GameSparks\\" + m_apiKey + "\\";

		int result = SHCreateDirectoryEx(NULL, base_path.c_str(), NULL);

		if (
			result != ERROR_SUCCESS &&
			result != ERROR_FILE_EXISTS &&
			result != ERROR_ALREADY_EXISTS
		)
		{
			DebugMsg("Failed to create directory.");
			assert(false);
		}
	}

	assert(!base_path.empty());

	return base_path + desired_name;

	#elif GS_TARGET_PLATFORM == GS_PLATFORM_ANDROID
    
    //////////////////////////////// Android
	// http://stackoverflow.com/questions/6276933/getfilesdir-from-ndk
	char buf[200]; // 64bit int can be 20 digits at most
	sprintf(buf,"/proc/%i/cmdline", (int)getpid());

	FILE* f = fopen(buf, "rb");
	if (!f)
	{
		DebugMsg("Failed to get writable path");
		return desired_name;
	}
	fread(buf, 1, sizeof(buf), f);
	fclose(f);
	// bytes not contains the list of null separated command line arguments, the string constructor below will copy until the first null byte
	return "/data/data/" + gsstl::string(buf) + "/" + desired_name;

	#elif GS_TARGET_PLATFORM == GS_PLATFORM_MAC

    ////////////////// OS X
    static gsstl::string base_path;
    if (base_path.empty())
    {
		// the environment might not be correctly setup, then we store data in /tmp
        gsstl::string writable_path("/tmp/GameSparks");

		if(char* homedir = getenv("HOME"))
			writable_path = homedir;

		writable_path += "/Library/Application Support/GameSparks/" + m_apiKey + "/";
        
        struct stat s;// = {0};
        
        if (0 != stat(writable_path.c_str(), &s) ) // Check if directory exists
        {
            mkdirp(writable_path.c_str());
        }
    
        base_path = writable_path;
    }
    
    return base_path + desired_name;
    
    #elif GS_TARGET_PLATFORM == GS_PLATFORM_IOS
    static gsstl::string base_path = gs_ios_get_writeable_base_path();
    return base_path + "/" + desired_name;
	#else
    #   error "ToWritableLocation not implemented for this platform. If you're planing on overriding it yourself, please define GS_OVERRIDE_TOWRITABLELOCATION"
	#endif
}

}} // namespace GameSparks { namespace Core {