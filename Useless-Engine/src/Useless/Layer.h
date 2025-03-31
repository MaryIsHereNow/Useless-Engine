//
// Created by 孙中行 on 2025/3/30.
//
#pragma once

#include "Useless/Core.h"
#include "Useless/Events/Event.h"

namespace Useless{

    ///层级类
    class UE_API Layer {
    public:
        explicit Layer(const std::string& name = "Layer");
        virtual ~Layer() = default;

        virtual void OnAttach(){ }
        virtual void OnDetach(){ }
        virtual void OnUpdate(){ }
        virtual void OnEvent(Event& event){ }

        inline const std::string& GetName() const {return _debugName;}
    protected:
        std::string _debugName;
    };

}
