#ifndef __NEUTRON_UTILS_BASICLOG_HPP__
#define __NEUTRON_UTILS_BASICLOG_HPP__

#include "../../Base/Object.hpp"
#include "../../Base/String.hpp"
#include "../../Base/StringStream.hpp"
#include "LogItem.hpp"
#include "LogLevel.hpp"

namespace ntk
{
    namespace Utils
    {
        /// @brief 日志输出器基类
        /// @tparam m_StringType 字符串类型
        /// @tparam m_LogItemType 日志项目类型
        /// @tparam m_OutputStreamType 输出流类型
        /// @tparam m_ContainerType 容器类型
        /// @tparam m_StringStreamType 字符串流类型
        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType, typename m_StringStreamType>
        class BasicLog : public Object
        {
        public:
            using StringType = m_StringType;
            using LogItemType = m_LogItemType;
            using OutputStreamType = m_OutputStreamType;
            using ContainerType = m_ContainerType;
            using StringStreamType = m_StringStreamType;
            using SelfType = BasicLog<StringType, LogItemType, OutputStreamType, ContainerType, StringStreamType>;

        protected:
            /// @brief 日志的项目
            ContainerType m_items;

            /// @brief 是否自动输出
            bool m_auto_output;

            /// @brief 输出流
            OutputStreamType *m_output;

        public:
            BasicLog();
            BasicLog(bool auto_output);
            BasicLog(OutputStreamType *output);
            BasicLog(bool auto_output, OutputStreamType *output);
            BasicLog(const SelfType &from);
            ~BasicLog();

        public:
            SelfType &operator=(const SelfType &from);

        public:
            /// @brief 获取所有日志
            /// @return 日志项目的容器
            const ContainerType &get_items() const;

            /// @brief 设置自动输出
            /// @param auto_output 是否自动输出
            /// @return 本对象
            SelfType &set_auto_output(bool auto_output);

            /// @brief 是否自动输出
            /// @return 是否自动输出
            bool is_auto_output() const;

            /// @brief 设置输出流
            /// @param output 输出流
            /// @return 本对象
            SelfType &set_output(OutputStreamType *output);

            /// @brief 获取输出流
            /// @return 输出流
            OutputStreamType *get_output();

        public:
            /// @brief 格式化日志
            /// @param item 日志项目
            /// @return 格式化后的结果
            virtual StringType format_log(const LogItemType &item);

            /// @brief 向输出流中输出所有日志
            virtual void output_all();

            /// @brief 清空m_items里储存的所有日志
            virtual void clear_all();

        public:
            /// @brief 输出一条日志
            /// @param level 日志的等级
            /// @param title 日志的标题
            /// @param content 日志的内容
            virtual void log(LogLevel::LogLevel level, const StringType &title, const StringType &content);

            /// @brief 输出一条UNKNOWN等级的日志
            /// @param title 日志的标题
            /// @param content 日志的内容
            virtual void logu(const StringType &title, const StringType &content);

            /// @brief 输出一条INFO等级的日志
            /// @param title 日志的标题
            /// @param content 日志的内容
            virtual void logi(const StringType &title, const StringType &content);

            /// @brief 输出一条DEBUG等级的日志
            /// @param title 日志的标题
            /// @param content 日志的内容
            virtual void logd(const StringType &title, const StringType &content);

            /// @brief 输出一条WARNING等级的日志
            /// @param title 日志的标题
            /// @param content 日志的内容
            virtual void logw(const StringType &title, const StringType &content);

            /// @brief 输出一条ERROR等级的日志
            /// @param title 日志的标题
            /// @param content 日志的内容
            virtual void loge(const StringType &title, const StringType &content);
        };
    } // namespace Utils

} // namespace ntk

#endif