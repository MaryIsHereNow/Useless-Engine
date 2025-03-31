//
// Created by 孙中行 on 25-3-21.
//
#pragma once

#include "Core.h"
#include "Window.h"
#include "Layer.h"
#include "LayerStack.h"
#include "Events/AppEvent.h"

namespace Useless {
    //Application类
    class UE_API Application{
    public:
        Application();
        virtual ~Application();

        void Run();
        void OnEvent(Event& event);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

    private:
        bool m_Running = true;
        std::unique_ptr<Window> m_Window;
        LayerStack m_LayerStack;

        bool OnWindowClose(WindowCloseEvent &event);
    };

    //在客户端中定义
    Application* CreateApplication();
}
