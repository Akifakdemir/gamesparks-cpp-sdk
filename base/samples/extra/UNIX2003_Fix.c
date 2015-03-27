#include "TargetConditionals.h"

#if TARGET_IPHONE_SIMULATOR
	#include <stdio.h>
	#include <unistd.h> 
	#include <string.h>
	#include <stdlib.h>
    #include <dirent.h>

    #if !defined(CC_TARGET_OS_IPHONE) // these are already defined in CCImage.c
        FILE *fopen$UNIX2003( const char *filename, const char *mode )
        {
            return fopen(filename, mode);
        }

        size_t fwrite$UNIX2003( const void *a, size_t b, size_t c, FILE *d )
        {
            return fwrite(a, b, c, d);
        }

        char* strerror$UNIX2003(int errornum)
        {
            return strerror(errornum);
        }
    #endif

    int fputs$UNIX2003(const char *res1, FILE *res2)
    {
        return fputs(res1,res2);
    }


	double strtod$UNIX2003(const char *nptr, char **endptr)
	{
	    return strtod(nptr, endptr);
	}


    DIR *opendir$INODE64$UNIX2003(const char * a)
    {
        return opendir(a);
    }

    int closedir$UNIX2003(DIR* dir)
    {
        return closedir(dir);
    }

    struct dirent *readdir$INODE64(DIR *dir)
    {
        return readdir(dir);
    }
#endif
