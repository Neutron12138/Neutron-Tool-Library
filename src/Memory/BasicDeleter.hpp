#ifndef __NEUTRONTL_MEMORY_BASICDELETER_HPP__
#define __NEUTRONTL_MEMORY_BASICDELETER_HPP__

#include "../Base/Object.hpp"

namespace ntl
{
    /// @brief 基础删除器
    /// @tparam m_DataType 指针类型
    template <typename m_DataType>
    class NTL_ALIGN BasicDeleter : public Object
    {
    public:
        using DataType = m_DataType;

        using SelfType = BasicDeleter<DataType>;
        using ParentType = Object;

    public:
        constexpr BasicDeleter() noexcept = default;
        constexpr BasicDeleter(const SelfType &from) noexcept = default;
        ~BasicDeleter() override = default;

    public:
        constexpr BasicDeleter &operator=(const SelfType &from) noexcept = default;

        void operator()(std::nullptr_t) const;
        virtual void operator()(DataType *ptr) const;
        virtual void operator()(void *ptr) const;
    };

    //
    // 数组特化
    //

    /// @brief 基础删除器，数组特化型
    /// @tparam m_DataType 指针类型
    template <typename m_DataType>
    class NTL_ALIGN BasicDeleter<m_DataType[]> : public Object
    {
    public:
        using DataType = m_DataType;

        using SelfType = BasicDeleter<DataType[]>;
        using ParentType = Object;

    public:
        constexpr BasicDeleter() noexcept = default;
        constexpr BasicDeleter(const SelfType &from) noexcept = default;
        ~BasicDeleter() override = default;

    public:
        constexpr BasicDeleter &operator=(const SelfType &from) noexcept = default;

        void operator()(std::nullptr_t) const;
        virtual void operator()(DataType *ptr) const;
        virtual void operator()(void *ptr) const;
    };

} // namespace ntl

#endif
