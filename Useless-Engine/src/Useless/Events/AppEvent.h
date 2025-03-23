//
// Created by 孙中行 on 25-3-23.
//
#pragma once

#include "Useless/uepch.h"
#include "Event.h"

namespace Useless {
    class UE_API WindowResizeEvent : public Event {
    public:
          WindowResizeEvent(int width, int height)
          : m_Width(width), m_Height(height) {}
          inline int GetWidth() const { return m_Width; }
          inline int GetHeight() const { return m_Height; }
          std::string ToString() const override {
                std::stringstream ss;
                ss << "WindowResizeEvent: " <<m_Width << ", " << m_Height;
                return ss.str();
          }
          EVENT_CLASS_TYPE(WindowResize)
          EVENT_CLASS_CATEGORY( static_cast<int>(EventCategory::Application) )
    private:
          unsigned int m_Width, m_Height;
    };

    class UE_API WindowCloseEvent : public Event {
    public:
          WindowCloseEvent() {}
          EVENT_CLASS_TYPE(WindowClose)
          EVENT_CLASS_CATEGORY( static_cast<int>(EventCategory::Application) )
    };

    class UE_API AppTickEvent : public Event {
      public:
        AppTickEvent() {}
        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY( static_cast<int>(EventCategory::Application) )
    };

    class UE_API AppUpdateEvent : public Event {
      public:
        AppUpdateEvent() {}
        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY( static_cast<int>(EventCategory::Application) )
    };

    class UE_API AppRenderEvent : public Event {
      public:
        AppRenderEvent() {}
        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY( static_cast<int>(EventCategory::Application) )
    };
}