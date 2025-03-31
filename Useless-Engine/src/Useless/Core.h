//
// Created by 孙中行 on 25-3-21.
//
#pragma once

#ifdef UE_PLATFORM_WINDOWS
//windows平台
    #ifdef UE_BUILD_DLL
        #define UE_API __declspec(dllexport)
    #else
        #define UE_API __declspec(dllimport)
    #endif
#elif defined(UE_PLATFORM_MACOS)
//macos平台
    #ifdef UE_BUILD_DLL
        #define UE_API __attribute__((visibility("default")))
    #else
        #define UE_API
    #endif
#endif

