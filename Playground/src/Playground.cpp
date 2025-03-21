#include <Useless.h>

class Playground : public UselessEngine::Application {
public:
    Playground() {}
    ~Playground() {}
};

UselessEngine::Application* UselessEngine::CreateApplication() {
    return new Playground();
}