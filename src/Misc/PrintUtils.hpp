#ifndef __NEUTRONTL_MISC_PRINTUTILS_HPP__
#define __NEUTRONTL_MISC_PRINTUTILS_HPP__

#include "../Base/Object.hpp"
#include "../Base/Type.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    /// @brief 输出工具
    class NTL_ALIGN PrintUtils : public Object
    {
    public:
        using SelfType = PrintUtils;
        using ParentType = Object;

    public:
        constexpr PrintUtils() noexcept = default;
        constexpr PrintUtils(const SelfType &from) noexcept = default;
        ~PrintUtils() override = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) = default;

    public:
        /// @brief 打印整个数组
        /// @tparam IteratorType 迭代器类型
        /// @param os 输出流
        /// @param begin 开始
        /// @param end 结束
        /// @param delimiter 分隔符
        template <typename IteratorType>
        static void print_array(OutputStream &os, const IteratorType &begin, const IteratorType &end, const String &delimiter = NTL_STRING(","));
    };
} // namespace ntl

#endif