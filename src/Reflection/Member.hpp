#ifndef __NEUTRONTL_REFLECTION_MEMBER_HPP__
#define __NEUTRONTL_REFLECTION_MEMBER_HPP__

#include "../Base/Type.hpp"
#include "../Base/BasicObject.hpp"

namespace ntl
{
    /// @brief 类成员
    template <typename m_MemberPointer>
    class NTL_ALIGN Member : public BasicObject
    {
    public:
        /// @brief 储存用的类型
        using MemberPointer = m_MemberPointer;

        using SelfType = Member;
        using ParentType = BasicObject;

    protected:
        /// @brief 指针
        MemberPointer m_pointer = nullptr;

    public:
        Member() = default;
        template <typename MemberType>
        Member(MemberType pointer);
        Member(const SelfType &from) = default;
        ~Member() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        MemberPointer get_pointer() const;
    };

} // namespace ntl

#endif