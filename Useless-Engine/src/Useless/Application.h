//
// Created by 孙中行 on 25-3-21.
//

#ifndef APPLICATION_H
#define APPLICATION_H

#include "Core.h"

namespace UselessEngine {

    class UE_API Application{
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    //在客户端中定义
    Application* CreateApplication();
}

#endif //APPLICATION_H
