//
// Created by 孙中行 on 25-3-23.
//
#pragma once

#include "uepch.h"
#include "Core.h"
#include "Events/Event.h"

namespace Useless {

    ///window属性结构体
    struct WindowProperties {
        ///窗口标题
        std::string Title;
        ///窗口大小
        unsigned int Width, Height;

        ///构造函数
        explicit WindowProperties( const std::string& title = "Useless-Engine",
                                   unsigned int width = 1280,
                                   unsigned int height = 720)
                                   : Title(title), Width(width), Height(height) { }
    };


    ///window类(抽象父类)
    class UE_API Window{
    public:
        ///窗口事件的回调函数
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() = default;

        ///Update生命周期函数
        virtual void OnUpdate() = 0;

        ///设置是否开启垂直同步的方法
        virtual void SetVSync(bool enabled) = 0;
        ///判断是否开启垂直同步的方法
        [[nodiscard]] virtual bool IsVSync() const = 0;

        ///得到窗口宽高的方法
        [[nodiscard]] virtual unsigned int GetWidth() const = 0;
        [[nodiscard]] virtual unsigned int GetHeight() const = 0;

        //设置回调函数的方法
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

        //创建窗口的静态方法
        static Window* Create(const WindowProperties& properties = WindowProperties());
    };
}