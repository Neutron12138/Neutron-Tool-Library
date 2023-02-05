#ifndef __NEUTRONTL_META_FUNDAMENTALTYPEINFO_HPP__
#define __NEUTRONTL_META_FUNDAMENTALTYPEINFO_HPP__

#include <type_traits>
#include "../Base/Object.hpp"

namespace ntl
{
    /// @brief 基本类型信息
    /// @tparam m_Type 类型
    template <typename m_Type>
    class FundamentalTypeInfo : public Object
    {
    public:
        using Type = m_Type;

        using SelfType = FundamentalTypeInfo<Type>;
        using ParentType = Object;

        /// @brief 基本类型
        enum FundamentalType
        {
            /// @brief 未知，不可能出现此结果
            Unknown = 0,

            /// @brief void类型
            Void,

            /// @brief 空指针类型
            NullPointer,

            /// @brief 整数类型
            Integral,

            /// @brief 浮点数类型
            FloatingPoint,

            /// @brief 数组类型
            Array,

            /// @brief 枚举类型
            Enum,

            /// @brief 联合体类型
            Union,

            /// @brief 非联合体类型
            Class,

            /// @brief 函数类型
            Function,

            /// @brief 指针类型
            Pointer,

            /// @brief 左值引用类型
            LValueReference,

            /// @brief 右值引用类型
            RValueReference,

            /// @brief 非静态成员对象类型
            MemberObjectPointer,

            /// @brief 非静态成员函数类型
            MemberFunctionPointer,

            /// @brief 总数
            Count = 14,
        };

    public:
        /// @brief 是否为void类型
        static constexpr bool is_void = std::is_void_v<Type>;

        /// @brief 是否为空指针类型
        static constexpr bool is_null_pointer = std::is_null_pointer_v<Type>;

        /// @brief 是否为整数类型
        static constexpr bool is_integral = std::is_integral_v<Type>;

        /// @brief 是否为浮点数类型
        static constexpr bool is_floating_point = std::is_floating_point_v<Type>;

        /// @brief 是否为数组类型
        static constexpr bool is_array = std::is_array_v<Type>;

        /// @brief 是否为枚举类型
        static constexpr bool is_enum = std::is_enum_v<Type>;

        /// @brief 是否为联合体类型
        static constexpr bool is_union = std::is_union_v<Type>;

        /// @brief 是否为非联合体类型
        static constexpr bool is_class = std::is_class_v<Type>;

        /// @brief 是否为函数类型
        static constexpr bool is_function = std::is_function_v<Type>;

        /// @brief 是否为指针类型
        static constexpr bool is_pointer = std::is_pointer_v<Type>;

        /// @brief 是否为左值引用类型
        static constexpr bool is_lvalue_reference = std::is_lvalue_reference_v<Type>;

        /// @brief 是否为右值引用类型
        static constexpr bool is_rvalue_reference = std::is_rvalue_reference_v<Type>;

        /// @brief 是否为非静态成员对象类型
        static constexpr bool is_member_object_pointer = std::is_member_object_pointer_v<Type>;

        /// @brief 是否为非静态成员函数类型
        static constexpr bool is_member_function_pointer = std::is_member_function_pointer_v<Type>;

        /// @brief 基本类型
        static constexpr FundamentalType fundamental_type =
            static_cast<FundamentalType>(
                (is_void ? FundamentalType::Void : FundamentalType::Unknown) |
                (is_null_pointer ? FundamentalType::NullPointer : FundamentalType::Unknown) |
                (is_integral ? FundamentalType::Integral : FundamentalType::Unknown) |
                (is_floating_point ? FundamentalType::FloatingPoint : FundamentalType::Unknown) |
                (is_array ? FundamentalType::Array : FundamentalType::Unknown) |
                (is_enum ? FundamentalType::Enum : FundamentalType::Unknown) |
                (is_union ? FundamentalType::Enum : FundamentalType::Unknown) |
                (is_class ? FundamentalType::Class : FundamentalType::Unknown) |
                (is_function ? FundamentalType::Function : FundamentalType::Unknown) |
                (is_pointer ? FundamentalType::Pointer : FundamentalType::Unknown) |
                (is_lvalue_reference ? FundamentalType::LValueReference : FundamentalType::Unknown) |
                (is_rvalue_reference ? FundamentalType ::RValueReference : FundamentalType::Unknown) |
                (is_member_object_pointer ? FundamentalType::MemberObjectPointer : FundamentalType::Unknown) |
                (is_member_function_pointer ? FundamentalType::MemberFunctionPointer : FundamentalType::Unknown));

    public:
        constexpr FundamentalTypeInfo() = default;
        constexpr explicit FundamentalTypeInfo(const SelfType &from) = default;
        ~FundamentalTypeInfo() override = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) = default;
    };
} // namespace ntl

#endif