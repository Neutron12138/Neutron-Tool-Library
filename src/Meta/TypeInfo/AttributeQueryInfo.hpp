#ifndef __NEUTRONTL_META_ATTRIBUTEQUERYINFO_HPP__
#define __NEUTRONTL_META_ATTRIBUTEQUERYINFO_HPP__

#include <type_traits>
#include "../../Base/Object.hpp"
#include "../../Base/Type.hpp"

namespace ntl
{
    /// @brief 属性查询信息
    /// @tparam m_Type 类型
    template <typename m_Type>
    class AttributeQueryInfo : public Object
    {
    public:
        using Type = m_Type;

        using SelfType = AttributeQueryInfo<Type>;
        using ParentType = Object;

    public:
        /// @brief 内存对齐大小
        static constexpr SizeT alignment_of = std::alignment_of_v<Type>;

        /// @brief 数组类型的维数
        static constexpr SizeT rank = std::rank_v<Type>;

    public:
        constexpr AttributeQueryInfo() = default;
        constexpr explicit AttributeQueryInfo(const SelfType &from) = default;
        ~AttributeQueryInfo() override = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) = default;
    };
} // namespace ntl

#endif