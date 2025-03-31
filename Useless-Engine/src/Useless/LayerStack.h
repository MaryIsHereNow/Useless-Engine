//
// Created by 孙中行 on 2025/3/30.
//
#pragma once

#include "Useless/Core.h"
#include "Useless/Layer.h"

namespace Useless{
    class UE_API LayerStack{
    public:
        LayerStack();
        ~LayerStack();

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        void PopLayer(Layer* layer);
        void PopOverlay(Layer* overlay);

        std::vector<Layer*>::iterator begin() {return _layers.begin();}
        std::vector<Layer*>::iterator end() {return _layers.end();}

    private:
        std::vector<Layer*> _layers;
        std::vector<Layer*>::iterator _layerInsert;
    };
}
