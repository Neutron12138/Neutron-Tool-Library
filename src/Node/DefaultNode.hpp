#ifndef __NEUTRONTL_NODE_DEFAULTNODE_HPP__
#define __NEUTRONTL_NODE_DEFAULTNODE_HPP__

#include <memory>
#include "Node.hpp"
#include "../Memory/SharedPointer.hpp"
#include "../Memory/WeakPointer.hpp"

namespace ntl
{
    /// @brief 默认节点
    class NTL_ALIGN DefaultNode : public Node<SharedPointer<DefaultNode>>
    {
    public:
        using SelfType = DefaultNode;
        using ParentType = Node<SharedPointer<DefaultNode>>;

    protected:
        /// @brief 父节点
        WeakPointer<DefaultNode> m_parent_node;

    public:
        DefaultNode() = default;
        explicit DefaultNode(const String &name);
        explicit DefaultNode(const String &name, const WeakPointer<DefaultNode> &parent_node);
        explicit DefaultNode(const SelfType &from) = default;
        ~DefaultNode() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        /// @brief 获取父节点
        /// @return 父节点
        inline virtual const WeakPointer<DefaultNode> &get_parent_node() const;

    public:
        inline virtual bool has_parent() const override;
    };

    template <typename SelfType, typename ParentType>
    void reset_parent_node(const String &name, const SharedPointer<SelfType> &self, SharedPointer<ParentType> &old_parent, SharedPointer<ParentType> &new_parent);
} // namespace ntl

#endif