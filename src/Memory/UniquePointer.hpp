#ifndef __NEUTRONTL_MEMORY_UNIQUEPOINTER_HPP__
#define __NEUTRONTL_MEMORY_UNIQUEPOINTER_HPP__

#include <memory>
#include "../Base/NonCopyable.hpp"
#include "Pointer.hpp"
#include "BasicDeleter.hpp"

namespace ntl
{
    /// @brief 专有指针类型，只能有一个指针拥有资源
    /// @tparam m_DataType 指针类型
    /// @tparam m_DeleterType 删除器类型
    template <typename m_DataType, typename m_DeleterType = BasicDeleter<m_DataType>>
    class NTL_ALIGN UniquePointer : public NonCopyable, public Pointer<m_DataType>, public std::unique_ptr<m_DataType, m_DeleterType>
    {
    public:
        using DataType = m_DataType;
        using DeleterType = m_DeleterType;
        using PointerType = Pointer<DataType>;
        using AutoPointerType = std::unique_ptr<DataType, DeleterType>;

        using SelfType = UniquePointer<DataType, DeleterType>;
        using ParentType = AutoPointerType;

    public:
        UniquePointer() = default;
        template <typename DataType2>
        UniquePointer(DataType2 *ptr);
        template <typename DataType2>
        UniquePointer(DataType2 *ptr, DeleterType deleter);
        UniquePointer(const SelfType &from) = delete;
        UniquePointer(SelfType &&from);
        virtual ~UniquePointer() override = default;

    public:
        using ParentType::operator=;
        SelfType &operator=(const SelfType &from) = delete;
        SelfType &operator=(SelfType &&from);

        DataType &operator*() const override;
        DataType *operator->() const override;

    public:
        DataType *get() const override;
    };

    /// @brief 专有数组类型，只能有一个指针拥有资源
    /// @tparam m_DataType 指针类型
    /// @tparam m_DeleterType 删除器类型
    template <typename m_DataType, typename m_DeleterType>
    class NTL_ALIGN UniquePointer<m_DataType[], m_DeleterType> : public NonCopyable, public Pointer<m_DataType[]>, public std::unique_ptr<m_DataType[], m_DeleterType>
    {
    public:
        using DataType = m_DataType;
        using DeleterType = m_DeleterType;
        using PointerType = Pointer<DataType[]>;
        using AutoPointerType = std::unique_ptr<DataType[], DeleterType>;

        using SelfType = UniquePointer<DataType[], DeleterType>;
        using ParentType = AutoPointerType;

    public:
        UniquePointer() = default;
        template <typename DataType2>
        UniquePointer(DataType2 *ptr);
        template <typename DataType2>
        UniquePointer(DataType2 *ptr, DeleterType deleter);
        UniquePointer(const SelfType &from) = delete;
        UniquePointer(SelfType &&from);
        virtual ~UniquePointer() override = default;

    public:
        using ParentType::operator=;
        SelfType &operator=(const SelfType &from) = delete;
        SelfType &operator=(SelfType &&from);

        DataType &operator*() const override;
        DataType *operator->() const override;
        DataType &operator[](SizeT index) const override;

    public:
        DataType *get() const override;
    };

    //
    // 辅助函数
    //

    /// @brief 创建一个新的专有指针
    /// @tparam DataType 数据类型
    /// @tparam ...ArgsType 参数类型列表
    /// @param ...args 参数列表
    /// @return 指针
    template <typename DataType, typename... ArgsType>
    UniquePointer<DataType, BasicDeleter<DataType>> make_unique(ArgsType &&...args);

    /// @brief 创建一个新的专有指针
    /// @tparam DataType 数据类型
    /// @tparam ...ArgsType 参数类型列表
    /// @param ...args 参数列表
    /// @return 指针
    template <typename DataType, typename DeleterType, typename... ArgsType>
    UniquePointer<DataType, DeleterType> make_unique_and_deleter(const DeleterType &deleter, ArgsType &&...args);

} // namespace ntl

#endif