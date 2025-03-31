//
// Created by 孙中行 on 2025/3/30.
//

#include "LayerStack.h"

namespace Useless{

    LayerStack::LayerStack() {
        _layerInsert = _layers.begin();
    }

    LayerStack::~LayerStack() {
        for(auto layer : _layers){
            delete layer;
        }
    }

    void LayerStack::PushLayer(Layer *layer) {
        _layerInsert = _layers.emplace(_layerInsert,layer);
    }

    void LayerStack::PushOverlay(Layer *overlay) {
        _layers.emplace_back(overlay);
    }

    void LayerStack::PopLayer(Layer *layer) {
        auto it = std::find(_layers.begin(),_layers.end(),layer);

        if(it != _layers.end()){
            _layers.erase(it);
            _layerInsert -- ;
        }
    }

    void LayerStack::PopOverlay(Layer *overlay) {
        auto it = std::find(_layers.begin(),_layers.end(),overlay);

        if(it != _layers.end()){
            _layers.erase(it);
        }
    }
}