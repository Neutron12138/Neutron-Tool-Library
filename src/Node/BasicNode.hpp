#ifndef __NEUTRONTL_NODE_BASICNODE_HPP__
#define __NEUTRONTL_NODE_BASICNODE_HPP__

#include "../Base/NamedObject.hpp"

namespace ntl
{
    /// @brief 基础节点类
    /// @tparam m_ChildNodeType 子节点类型，继承自BasicNode
    template <typename m_ChildNodeType>
    class NTL_ALIGN BasicNode : public NamedObject
    {
    public:
        using ChildNodeType = m_ChildNodeType;

        using SelfType = BasicNode<ChildNodeType>;
        using ParentType = NamedObject;

    public:
        BasicNode() = default;
        BasicNode(const String &name);
        BasicNode(const SelfType &from) = default;
        ~BasicNode() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
        virtual ChildNodeType &operator[](const String &name) = 0;

    public:
        /// @brief 获取一个子节点
        /// @param name 要获取的子节点的名称
        /// @return 子节点
        virtual const ChildNodeType &get_child_node(const String &name) const = 0;

        /// @brief 设置一个子节点
        /// @param name 要设置的子节点的名称
        /// @param child_node 子节点
        virtual void set_child_node(const String &name, const ChildNodeType &child_node) = 0;

        /// @brief 添加一个子节点
        /// @param name 要添加的子节点的名称
        /// @param child_node 要添加的子节点
        virtual void add_child_node(const String &name, const ChildNodeType &child_node) = 0;

        /// @brief 移除一个子节点
        /// @param name 要移除的子节点的名称
        virtual void remove_child_node(const String &name) = 0;

        /// @brief 判断一个子节点是否存在
        /// @param name 要判断的子节点的名称
        /// @return 子节点是否存在
        virtual bool is_exist(const String &name) const = 0;

        /// @brief 判断本节点是否存在父级
        /// @return 是否存在父级
        virtual bool has_parent() const = 0;

        /// @brief 判断本节点是否存在子级
        /// @return 是否存在子级
        virtual bool has_childs() const = 0;

        /// @brief 清除所有子节点
        virtual void clear_all() = 0;
    };

} // namespace ntl

#endif