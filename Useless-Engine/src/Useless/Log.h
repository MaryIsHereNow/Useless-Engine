//
// Created by 孙中行 on 25-3-22.
//

#ifndef LOG_H
#define LOG_H

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Useless{
    ///日志类
    class UE_API Log {
    public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }      //get
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }  //get
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

#define UE_CORE_ERROR(...) ::Useless::Log::GetCoreLogger()->error(__VA_ARGS__)
#define UE_CORE_WARN(...) ::Useless::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define UE_CORE_INFO(...) ::Useless::Log::GetCoreLogger()->info(__VA_ARGS__)
#define UE_CORE_TRACE(...) ::Useless::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define UE_CORE_DEBUG(...) ::Useless::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define UE_CORE_FATAL(...) ::Useless::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define UE_ERROR(...) ::Useless::Log::GetClientLogger()->error(__VA_ARGS__)
#define UE_WARN(...) ::Useless::Log::GetClientLogger()->warn(__VA_ARGS__)
#define UE_INFO(...) ::Useless::Log::GetClientLogger()->info(__VA_ARGS__)
#define UE_TRACE(...) ::Useless::Log::GetClientLogger()->trace(__VA_ARGS__)
#define UE_DEBUG(...) ::Useless::Log::GetClientLogger()->debug(__VA_ARGS__)
#define UE_FATAL(...) ::Useless::Log::GetClientLogger()->fatal(__VA_ARGS__)

#endif //LOG_H
