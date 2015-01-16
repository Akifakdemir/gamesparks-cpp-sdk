#ifndef GSSTL_H_INCLUDED
#define GSSTL_H_INCLUDED

#pragma once

/*
	This header is here, so that we can easily switch between
	different STL implementations. Current choices are:
		- STD-STL (what ever your compiler uses)

*/

#if defined(GS_USE_EASTL)
#	undef USE_STD_STL
#else
#	define USE_STD_STL 1
#endif /* defined(GS_USE_EASTL) */


#if !defined(STL_FUNCTIONAL_SUPPORTED)
#define STL_FUNCTIONAL_SUPPORTED 1
#endif

// std function can only be used, if we have at least c++11 
#if (__cplusplus >= 201103L || _MSC_VER >= 1800 ) && USE_STD_STL && STL_FUNCTIONAL_SUPPORTED
#	define GS_USE_STD_FUNCTION 1
#	include <functional>
#else
#	undef GS_USE_STD_FUNCTION
#endif /* __cplusplus >= 201103L */

// include required headers
#if defined(GS_USE_EASTL)
#	include "EASTL/string.h"
#	include "EASTL/vector.h"
#	include "EASTL/list.h"
#	include "EASTL/map.h"
#	include <EASTL/algorithm.h>
#else
#	include <string>
#	include <vector>
#	include <list>
#	include <map>
#	include <algorithm>
#endif /* defined(GS_USE_EASTL */

namespace gsstl
{
#if defined(GS_USE_EASTL)
    using namespace eastl;
#else
    using namespace std;
#endif /* defined(USE_EASTL */
}

#ifndef nullptr
namespace gsstl
{
    //based on SC22/WG21/N2431 = J16/07-0301
    struct nullptr_t
    {
        template<typename any> operator any * () const
        {
            return 0;
        }
        template<class any, typename T> operator T any:: * () const
        {
            return 0;
        }
        
#ifdef _MSC_VER
        struct pad {};
        pad __[sizeof(void*)/sizeof(pad)];
#else
        char __[sizeof(void*)];
#endif
    private:
        //  nullptr_t();// {}
        //  nullptr_t(const nullptr_t&);
        //  void operator = (const nullptr_t&);
        void operator &() const;
        template<typename any> void operator +(any) const
        {
            /*I Love MSVC 2005!*/
        }
        template<typename any> void operator -(any) const
        {
            /*I Love MSVC 2005!*/
        }
    };
    static const nullptr_t nullptr_instance = {};
}

#define nullptr gsstl::nullptr_instance
#endif



#endif /* GSSTL_H_INCLUDED */
