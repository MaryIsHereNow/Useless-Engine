//
// Created by 孙中行 on 25-3-23.
//
#pragma once

#include "Useless/Window.h"
#include "glfw/glfw3.h"

namespace Useless {
    class MacWindow : public Window {
    public:
        MacWindow(const WindowProperties& properties);
        virtual ~MacWindow();

        void OnUpdate() override;

        unsigned int GetWidth() const override {return m_Data.Width;}
        unsigned int GetHeight() const override {return m_Data.Height;}

        void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;

    private:
        virtual void Init(const WindowProperties& properties);
        virtual void Shutdown();
        GLFWwindow* m_Window;

        struct WindowData {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;
            EventCallbackFn EventCallback;
        };

        WindowData m_Data;
    };
}