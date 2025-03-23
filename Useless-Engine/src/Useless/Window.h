//
// Created by 孙中行 on 25-3-23.
//
#pragma once

#include "uepch.h"
#include "Core.h"
#include "Events/Event.h"

namespace Useless {

    //window属性结构体
    struct WindowProperties {
        std::string Title;
        unsigned int Width, Height;

        WindowProperties( const std::string& title = "Useless-Engine",
                          unsigned int width = 1280,
                          unsigned int height = 720) : Title(title), Width(width), Height(height) { }
    };

    //window类
    class UE_API Window{
    public:
        //回调函数
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() { }

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProperties& properties = WindowProperties());
    };
}