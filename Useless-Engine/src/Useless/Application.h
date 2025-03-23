//
// Created by 孙中行 on 25-3-21.
//
#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/AppEvent.h"

namespace Useless {
    //Application类
    class UE_API Application{
    public:
        Application();
        virtual ~Application();

        void Run();
        void OnEvent(Event& event);

    private:
        bool OnWindowClose(WindowCloseEvent &event);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    //在客户端中定义
    Application* CreateApplication();
}
