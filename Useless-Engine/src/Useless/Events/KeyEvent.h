//
// Created by 孙中行 on 25-3-23.
//
#pragma once

#include "Useless/uepch.h"
#include "Event.h"

namespace Useless {
    class UE_API KeyEvent : public Event {
    public:
        inline int GetKeyCode() const { return m_Keycode; }
        EVENT_CLASS_CATEGORY( static_cast<int>(EventCategory::Keyboard) | static_cast<int>(EventCategory::Keyboard))
    protected:
        KeyEvent(int keycode) : m_Keycode(keycode) {}
        int m_Keycode;
    };

    class UE_API KeyPressedEvent : public KeyEvent {
    public:
        KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), m_RepeatCount(repeatCount) {}
        inline int GetRepeatCount() const { return m_RepeatCount; }
        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_Keycode << ", " << m_RepeatCount<< " Repeats";
            return ss.str();
        }
        EVENT_CLASS_TYPE(KeyPressed)

    private:
        int m_RepeatCount;
    };

    class UE_API KeyReleasedEvent : public KeyEvent {
    public:
        KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}
        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_Keycode;
            return ss.str();
        }
        EVENT_CLASS_TYPE(KeyReleased)
    };
}