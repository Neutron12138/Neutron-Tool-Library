#ifndef __NEUTRONTL_NODE_DEFAULTNODE_CPP__
#define __NEUTRONTL_NODE_DEFAULTNODE_CPP__

#include "DefaultNode.hpp"

namespace ntl
{
    DefaultNode::DefaultNode(
        const String &name)
        : DefaultNode::ParentType(name) {}

    DefaultNode::DefaultNode(
        const String &name,
        const typename DefaultNode::ParentNodeType &parent_node)
        : DefaultNode::ParentType(name), m_parent_node(parent_node) {}

    const typename DefaultNode::ParentNodeType &
    DefaultNode::get_parent_node() const
    {
        return m_parent_node;
    }

    bool
    DefaultNode::has_parent() const
    {
        return m_parent_node.lock().get() != nullptr;
    }

    template <typename SelfType, typename ParentType>
    void
    reset_parent_node(
        const String &name,
        const SharedPointer<SelfType> &self,
        SharedPointer<ParentType> &old_parent,
        SharedPointer<ParentType> &new_parent)
    {
        new_parent->add_child_node(name, self);
        old_parent->remove_child_node(name);
    }

} // namespace ntl

#endif
