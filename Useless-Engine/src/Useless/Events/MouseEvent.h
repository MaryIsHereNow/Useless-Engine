//
// Created by 孙中行 on 25-3-23.
//
#pragma once

#include "Useless/uepch.h"
#include "Event.h"

namespace Useless {
    class UE_API MouseMovedEvent : public Event {
    public:
        MouseMovedEvent(int x, int y) : m_X(x), m_Y(y) {}

        inline float GetX() const { return m_X; }
        inline float GetY() const { return m_Y; }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_X << ", " << m_Y;
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(static_cast<int>(EventCategory::Mouse) | static_cast<int>(EventCategory::Input))
    private:
        float m_X, m_Y;
    };

    class UE_API MouseScrolledEvent : public Event {
    public:
        MouseScrolledEvent (int xOffset, int yOffset) : m_XOffset(xOffset), m_YOffset(yOffset) {}
        inline float GetXOffset() const { return m_XOffset; }
        inline float GetYOffset() const { return m_YOffset; }
        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(static_cast<int>(EventCategory::Mouse) | static_cast<int>(EventCategory::Input))
    private:
        float m_XOffset, m_YOffset;
    };

    class UE_API MouseButtonEvent : public Event {
      public:
        inline int GetMouseButton() const { return m_Button; }
        EVENT_CLASS_CATEGORY(static_cast<int>(EventCategory::Mouse) | static_cast<int>(EventCategory::Input))
        protected:
          MouseButtonEvent(int button) : m_Button(button) {}
          int m_Button;
    };

    class UE_API MouseButtonPressedEvent : public MouseButtonEvent {
      public:
        MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}
        EVENT_CLASS_TYPE(MouseButtonPressed)
           std::string ToString() const override {
             std::stringstream ss;
             ss << "MouseButtonPressedEvent: " << m_Button;
             return ss.str();
           }
    };

    class UE_API MouseButtonReleasedEvent : public MouseButtonEvent {
      public:
        MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}
        EVENT_CLASS_TYPE(MouseButtonReleased)
        std::string ToString() const override {
          std::stringstream ss;
          ss << "MouseButtonReleasedEvent: " << m_Button;
          return ss.str();
        }
    };
}