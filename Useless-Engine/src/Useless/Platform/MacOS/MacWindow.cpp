//
// Created by 孙中行 on 25-3-23.
//

#include "Useless/uepch.h"
#include "MacWindow.h"

#include "Useless/Events/AppEvent.h"
#include "Useless/Events/KeyEvent.h"
#include "Useless/Events/MouseEvent.h"

#include <Useless/Log.h>

namespace Useless {
    static bool s_GLFWInitialized = false;

    //平台抽象
    Window* Window::Create(const WindowProperties& properties) {
        return new MacWindow(properties);
    }

    MacWindow::MacWindow(const WindowProperties& properties) {
        MacWindow::Init(properties);
    }

    MacWindow::~MacWindow() {
        MacWindow::Shutdown();
    }

    ///初始化Window的方法
    void MacWindow::Init(const WindowProperties& properties) {
        m_Data.Title = properties.Title;
        m_Data.Width = properties.Width;
        m_Data.Height = properties.Height;

        //控制台输出
        UE_LOG_CORE_INFO("Creating window {0},{1},{2}",properties.Title,properties.Width,properties.Height);

        if (!s_GLFWInitialized) {
            //TODO glfwTerminate on system shutdown
            int success = glfwInit();
            if (!success) {
                UE_LOG_CORE_ERROR("Failed to initialize GLFW");
                __builtin_trap();
            }

            glfwSetErrorCallback([](int error, const char* description) {
                UE_LOG_ERROR("GLFW Error {0}", error);
            });

            s_GLFWInitialized = true;
        }
        m_Window = glfwCreateWindow(static_cast<int>(properties.Width), static_cast<int>(properties.Height), m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        if (!m_Window) {
            UE_LOG_CORE_ERROR("Failed to create GLFW window");
            glfwTerminate();
            __builtin_trap();
        }

        int status = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
        if(!status){
            UE_LOG_CORE_ERROR("failed to init Glad");
            __builtin_trap();
        }

        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);

        //设置GLFW的回调函数
        //1.设置窗口大小事件回调
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            WindowResizeEvent event(width, height);
            data.Width = width;
            data.Height = height;
            data.EventCallback(event);
        });
        //2.关闭窗口事件回调
        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data.EventCallback(event);
        });
        //3.按键事件回调
        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            switch (action) {
                case GLFW_PRESS: {
                    KeyPressedEvent event(key, 0);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    KeyReleasedEvent event(key);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_REPEAT: {
                    KeyPressedEvent event(key, 1);
                    data.EventCallback(event);
                    break;
                }
            }
        });
        //4.鼠标事件回调
        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            switch (action) {
                case GLFW_PRESS: {
                    MouseButtonPressedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    MouseButtonReleasedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
            }
        });
        //5.鼠标滚轮事件回调
        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseScrolledEvent event((float)xOffset,(float)yOffset);
            data.EventCallback(event);
        });
        //6.光标位置事件回调
        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseMovedEvent event((float)xPos,(float)yPos);
            data.EventCallback(event);
        });
    }

    ///关闭Window的方法
    void MacWindow::Shutdown() {
        glfwDestroyWindow(m_Window);
    }

    void MacWindow::OnUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }
    void MacWindow::SetVSync(const bool enabled) {
        if (enabled) {
            glfwSwapInterval(1);
        }
        else {
            glfwSwapInterval(0);
        }
        m_Data.VSync = enabled;
    }
    bool MacWindow::IsVSync() const {
        return m_Data.VSync;
    }
}
