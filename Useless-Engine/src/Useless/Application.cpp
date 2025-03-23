//
// Created by 孙中行 on 25-3-21.
//

#include "uepch.h"
#include "Application.h"
#include "Log.h"
#include "Events/AppEvent.h"

namespace Useless {

    Application::Application() {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(std::bind(&Application::OnEvent,this,std::placeholders::_1));
    }

    Application::~Application() {
    }

    void Application::OnEvent(Event& event) {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose,this,std::placeholders::_1));
        UE_LOG_CORE_INFO(event.ToString());
    }

    void Application::Run() {
        while (m_Running) {
            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& event) {
        m_Running = false;
        return true;
    }
}
