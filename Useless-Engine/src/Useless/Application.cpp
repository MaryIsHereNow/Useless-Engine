//
// Created by 孙中行 on 25-3-21.
//

#include "uepch.h"
#include "Application.h"
#include "Log.h"
#include "Events/AppEvent.h"
#include "glad/glad.h"

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

        for(auto it = m_LayerStack.end() ; it != m_LayerStack.begin();){
            (*--it)->OnEvent(event);
            if(event.IsHandled())
                break;
        }
    }

    void Application::Run() {
        while (m_Running) {
            glClearColor(1,0,1,1);
            glClear(GL_COLOR_BUFFER_BIT);

            for(Layer* layer : m_LayerStack)
                layer->OnUpdate();

            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& event) {
        m_Running = false;
        return true;
    }

    void Application::PushLayer(Layer* layer) {
        m_LayerStack.PushLayer(layer);
    }


    void Application::PushOverlay(Layer* layer) {
        m_LayerStack.PushOverlay(layer);
    }
}
