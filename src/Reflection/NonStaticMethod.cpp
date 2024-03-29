#ifndef __NEUTRONTL_REFLECTION_NONSTATICMETHOD_CPP__
#define __NEUTRONTL_REFLECTION_NONSTATICMETHOD_CPP__

#include <iostream>
#include "NonStaticMethod.hpp"
#include "../Exception/InvalidArgumentException.hpp"
#include "../String/StringUtils.hpp"
#include "../Exception/NullPointerException.hpp"

namespace ntl
{
    template <typename MethodType>
    NonStaticMethod::NonStaticMethod(
        MethodType pointer,
        SizeT args_count)
        : NonStaticMethod::ParentType(
              pointer,
              args_count) {}

    template <typename MethodType>
    NonStaticMethod::NonStaticMethod(
        MethodType pointer,
        SizeT args_count,
        const MethodSign &sign)
        : NonStaticMethod::ParentType(
              pointer,
              args_count,
              sign) {}

    template <typename ReturnType, typename... ArgsType>
    ReturnType
    NonStaticMethod::call(
        void *object,
        ArgsType &&...args) const
    {
        if (m_pointer == nullptr || object == nullptr)
            throw NullPointerException(
                NTL_MAKE_STATEMENT_INFO("template <typename ReturnType, typename... ArgsType> ReturnType NonStaticMethod::call(BasicObject &object,ArgsType &&...args) const"));

        const SizeT args_count = sizeof...(args);
        if (args_count != m_args_count)
            throw InvalidArgumentException(
                StringUtils::to_string(
                    NTL_STRING("The number of parameters is wrong, "),
                    m_args_count,
                    NTL_STRING(" are required, but "),
                    args_count,
                    NTL_STRING(" are provided")),
                NTL_MAKE_STATEMENT_INFO("template <typename ReturnType, typename... ArgsType> ReturnType NonStaticMethod::call(BasicObject &object,ArgsType &&...args) const"));

        using MethodType = ReturnType (BasicObject::*)(ArgsType...);
        return (reinterpret_cast<BasicObject *>(object)->*reinterpret_cast<MethodType>(m_pointer))(
            std::forward<ArgsType>(args)...);
    }

} // namespace ntl

#endif