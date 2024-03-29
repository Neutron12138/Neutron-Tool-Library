#ifndef __NEUTRONTL_BASE_OBJECT_CPP__
#define __NEUTRONTL_BASE_OBJECT_CPP__

#include "Object.hpp"
#include "../String/StringUtils.hpp"
#include "../Serialization/Serialization.hpp"
#include "../Serialization/Deserializer.hpp"

namespace ntl
{
    Serialization
    serialize(
        const Object &object)
    {
        return Serialization(
            StringUtils::to_string(
                NTL_STRING("ntl::Object at "),
                &object));
    }

    template <>
    Object
    deserialize(
        const Serialization &serialization)
    {
        return Object();
    }

} // namespace ntl

#endif
