//
// Created by 孙中行 on 25-3-21.
//

#ifndef CORE_H
#define CORE_H

//windows平台
#ifdef UE_PLATFORM_WINDOWS
    #ifdef UE_BUILD_DLL
        #define UE_API __declspec(dllexport)
    #else
        #define UE_API __declspec(dllimport)
    #endif

//macos平台
#elif defined(UE_PLATFORM_MACOS)
    #ifdef UE_BUILD_DLL
        #define UE_API __attribute__((visibility("default")))
    #else
        #define UE_API
    #endif


#endif

#endif //CORE_H
