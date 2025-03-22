//
// Created by 孙中行 on 25-3-21.
//
#pragma once

#include "Core.h"

namespace Useless {
    //Application类
    class UE_API Application{
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    //在客户端中定义
    Application* CreateApplication();
}