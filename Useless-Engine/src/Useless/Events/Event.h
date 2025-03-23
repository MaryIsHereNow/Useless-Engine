//
// Created by 孙中行 on 25-3-22.
//
#pragma once

#include "Useless/Core.h"

namespace Useless {
    //事件类型枚举
    enum class EventType{
        None = 0,
        WindowClose,WindowResize,WindowFocus,WindowLostFocus,WindowMoved,
        AppTick,AppUpdate,AppRender,
        KeyPressed,KeyReleased,KeyTyped,
        MouseButtonPressed,MouseButtonReleased,MouseMoved,MouseScrolled
    };

    //事件分类枚举(位运算Flag)
    enum class EventCategory{
        None = 0,
        Application   = 1 << 0,
        Input         = 1 << 1,
        Keyboard      = 1 << 2,
        Mouse         = 1 << 3,
        MouseButton   = 1 << 4,
    };

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
                    virtual EventType GetType() const override { return GetStaticType(); }\
                    virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}


    //事件类
    class UE_API Event{
        friend class EventDispatcher;
    public:
        virtual EventType GetType() const = 0;          //事件类型
        virtual const char* GetName() const = 0;        //事件名
        virtual int GetCategoryFlags() const = 0;       //事件分类
        virtual std::string ToString() const { return GetName();}

        ///判断是否属于某个事件分类的方法
        inline bool IsInCategory(EventCategory category) { return GetCategoryFlags() & static_cast<int>(category); }
    protected:
        bool m_Handled = false;
    };

    class EventDispatcher {
        template<typename T>
        using EventFn = std::function<bool(T&)>;
    public:
        EventDispatcher(Event& event) : m_Event(event) { }

        template<typename T>
        bool Dispatch(EventFn<T> func) {
            if (m_Event.GetType() == T::GetStaticType()) {
                m_Event.m_Handled = func(*(T*)&m_Event);
                return true;
            }
            return false;
        }
    private:
        Event& m_Event;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e) {
        return os << e.ToString();
    }
}