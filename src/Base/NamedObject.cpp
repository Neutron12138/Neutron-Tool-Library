#ifndef __NEUTRONTL_BASE_NAMEDOBJECT_CPP__
#define __NEUTRONTL_BASE_NAMEDOBJECT_CPP__

#include "NamedObject.hpp"

namespace ntl
{
    template <typename m_StringType>
    NamedObject<m_StringType>::NamedObject(const m_StringType &name) : m_name(name) {}

    template <typename m_StringType>
    const m_StringType &NamedObject<m_StringType>::get_name() const
    {
        return m_name;
    }

    template <typename m_StringType>
    void NamedObject<m_StringType>::set_name(const m_StringType &name)
    {
        m_name = name;
    }
} // namespace ntl

#endif