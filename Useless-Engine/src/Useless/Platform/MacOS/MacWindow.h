//
// Created by 孙中行 on 25-3-23.
//
#pragma once

#include "Useless/Window.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Useless {

    ///MacOS下的窗口类
    class MacWindow : public Window {
    public:
        explicit MacWindow(const WindowProperties& properties);
        ~MacWindow() override;

        void OnUpdate() override;

        [[nodiscard]] unsigned int GetWidth() const override {return m_Data.Width;}
        [[nodiscard]] unsigned int GetHeight() const override {return m_Data.Height;}

        void SetVSync(bool enabled) override;
        [[nodiscard]] bool IsVSync() const override;

        void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }

    private:
        ///窗口数据结构体
        struct WindowData {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;
            EventCallbackFn EventCallback;
        };

        WindowData m_Data;
        GLFWwindow* m_Window;

        virtual void Shutdown();
        virtual void Init(const WindowProperties& properties);
    };
}