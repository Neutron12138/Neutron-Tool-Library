#ifndef __NEUTRONTL_BASE_NAMEDOBJECT_CPP__
#define __NEUTRONTL_BASE_NAMEDOBJECT_CPP__

#include "NamedObject.hpp"

namespace ntl
{
    inline NamedObject::NamedObject(
        const String &name)
        : m_name(name) {}

    inline const String &
    NamedObject::get_name() const
    {
        return m_name;
    }

    void
    NamedObject::set_name(
        const String &name)
    {
        m_name = name;
    }
} // namespace ntl

#endif