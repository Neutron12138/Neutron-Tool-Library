#ifndef __NEUTRONTL_CONFIG_HPP__
#define __NEUTRONTL_CONFIG_HPP__

// NTL类的说明符
// NTL_ALIGN 内存对齐

// 可选参数有：

// NEUTRONTL_CONFIG_NO_INFO 不包含Info.hpp
// NEUTRONTL_CONFIG_NO_DEBUG 不包含Debug.hpp与Debug.cpp
// NEUTRONTL_CONFIG_NO_INCLUDES 不包含Includes.hpp

// NEUTRONTL_CONFIG_USE_WCHAR 使用宽字节字符串而不是多字节字符串
// NEUTRONTL_CONFIG_USE_APPLICATION 使用NTL提供的Main入口

// NEUTRONTL_CONFIG_USE_CPP20 使用C++20

// 实现：

#ifdef NEUTRONTL_CONFIG_USE_WCHAR

#define NTL_CHAR(ch) L##ch
#define NTL_CSTRING(str) L##str
#define NTL_STRING(str) ntl::String(L##str)

#else

#define NTL_CHAR(ch) ch
#define NTL_CSTRING(str) str
#define NTL_STRING(str) ntl::String(str)

#endif

// 禁用内存对齐
#define NTL_ALIGN alignas(1)

#if defined(NEUTRONTL_CONFIG_USE_CPP20)
#if __cplusplus >= 202002L
#define NEUTRONTL_CPP20 true
#else
#error The compiler does not support C++20.
#endif
#endif

#ifndef NEUTRONTL_CPP20
#define NEUTRONTL_CPP20 false
namespace ntl
{
    namespace cpp20
    {
        enum
        {
            /// @brief 不支持C++20
            NotSupport
        };
    } // namespace cpp20

} // namespace ntl

#endif

#endif