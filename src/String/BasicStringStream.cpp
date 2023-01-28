#ifndef __NEUTRONTL_STRING_BASICSTRINGSTREAM_CPP__
#define __NEUTRONTL_STRING_BASICSTRINGSTREAM_CPP__

#include "BasicStringStream.hpp"

namespace ntl
{
    template <typename m_TraitsType, typename m_AllocatorType>
    BasicStringStream<m_TraitsType, m_AllocatorType>::BasicStringStream(const typename BasicStringStream<m_TraitsType, m_AllocatorType>::StdWStringType &wstr,
                                                                        std::ios_base::openmode mode) : BasicStringStream<m_TraitsType, m_AllocatorType>::ParentType(wstr, mode) {}

    template <typename m_TraitsType, typename m_AllocatorType>
    typename BasicStringStream<m_TraitsType, m_AllocatorType>::StringType BasicStringStream<m_TraitsType, m_AllocatorType>::to_string() const
    {
        typename BasicStringStream<m_TraitsType, m_AllocatorType>::StdWStringType string = typename BasicStringStream<m_TraitsType, m_AllocatorType>::ParentType::str();
        typename BasicStringStream<m_TraitsType, m_AllocatorType>::StringType result(string);
        return result;
    }
} // namespace ntl

#endif