#ifndef __NEUTRONTL_EXCEPTION_EXCEPTION_CPP__
#define __NEUTRONTL_EXCEPTION_EXCEPTION_CPP__

#include <iostream>
#include "Exception.hpp"

namespace ntl
{
    Exception::Exception(
        const String &what,
        const String &why,
        const String &where)
        : m_what(what), m_why(why), m_where(where) {}

    inline const String &
    Exception::what() const
    {
        return m_what;
    }

    inline const String &
    Exception::why() const
    {
        return m_why;
    }

    inline const String &
    Exception::where() const
    {
        return m_where;
    }

    OutputStream &
    operator<<(
        OutputStream &os,
        const Exception &exception)
    {
        os << NTL_STRING("Exception:") << std::endl
           << NTL_STRING("what:") << exception.what() << std::endl
           << NTL_STRING("why:") << exception.why() << std::endl
           << NTL_STRING("where:") << exception.where() << std::endl;
        return os;
    }
} // namespace ntl

#endif