//
// Created by 孙中行 on 25-3-22.
//
#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Useless{
    ///日志类 提供控制台输出的API
    class UE_API Log {
    public:
        ///初始化Log(spdlog)的方法
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }      //getter
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }  //getter
    private:
        ///核心logger和客户logger
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

///实现日志输出的宏定义
#define UE_LOG_CORE_ERROR(...) ::Useless::Log::GetCoreLogger()->error(__VA_ARGS__)
#define UE_LOG_CORE_WARN(...) ::Useless::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define UE_LOG_CORE_INFO(...) ::Useless::Log::GetCoreLogger()->info(__VA_ARGS__)
#define UE_LOG_CORE_TRACE(...) ::Useless::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define UE_LOG_CORE_DEBUG(...) ::Useless::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define UE_LOG_CORE_FATAL(...) ::Useless::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define UE_LOG_ERROR(...) ::Useless::Log::GetClientLogger()->error(__VA_ARGS__)
#define UE_LOG_WARN(...) ::Useless::Log::GetClientLogger()->warn(__VA_ARGS__)
#define UE_LOG_INFO(...) ::Useless::Log::GetClientLogger()->info(__VA_ARGS__)
#define UE_LOG_TRACE(...) ::Useless::Log::GetClientLogger()->trace(__VA_ARGS__)
#define UE_LOG_DEBUG(...) ::Useless::Log::GetClientLogger()->debug(__VA_ARGS__)
#define UE_LOG_FATAL(...) ::Useless::Log::GetClientLogger()->fatal(__VA_ARGS__)
