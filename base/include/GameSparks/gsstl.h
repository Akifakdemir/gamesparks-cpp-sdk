// Copyright 2015 GameSparks Ltd 2015, Inc. All Rights Reserved.
#ifndef gsstl_h__
#define gsstl_h__

#pragma once

/*!
	This header is here, so that we can easily switch between
	different STL implementations. Current choices are:
		- STD-STL (what ever your compiler uses)

*/



#if defined(DOXYGEN)
/// wether to use EASTL or the STL provided by the compiler
/// @ingroup CompileOptions
#define GS_USE_EASTL <platform-dependend>

/// if set to 1, the stl provided by the compiler is used.
/// @ingroup CompileOptions
#define USE_STD_STL <platform-dependend>

/// if set to 1, std::function will be used for callbacks. This also enables support for C++11 lambdas.
/// This is disabled on Marmalade.
/// @ingroup CompileOptions
#define STL_FUNCTIONAL_SUPPORTED <platform-dependend>

#endif



#if defined(GS_USE_EASTL)
#	undef USE_STD_STL
#else
#	define USE_STD_STL 1
#endif /* defined(GS_USE_EASTL) */


#if !defined(STL_FUNCTIONAL_SUPPORTED) && !defined(MARMALADE)
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
#	include "EASTL/set.h"
#	include <EASTL/algorithm.h>
#else
#	include <string>
#	include <vector>
#	include <list>
#	include <map>
#	include <algorithm>
#	include <set>
#endif /* defined(GS_USE_EASTL */

//! This namespace provides forwarding to the concrete STL implementation used. If GS_USE_EASTL is set to 1, EASTL (https://github.com/paulhodge/EASTL) is used. The STL provided by your compiler otherwise.
namespace gsstl
{
#if defined(GS_USE_EASTL)
    using namespace eastl;
#else
    using namespace std;
#endif /* defined(USE_EASTL */
}

#if !defined(nullptr) && !defined(DOXYGEN)
namespace gsstl
{
    //!  a nullptr implementation for compilers that do not support the C++11 nullptr yet.
    //! based on SC22/WG21/N2431 = J16/07-0301
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


#endif // gsstl_h__
