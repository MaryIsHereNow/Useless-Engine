#include <Useless.h>

class Playground : public Useless::Application {
public:
    Playground() {}
    ~Playground() {}
};

Useless::Application* Useless::CreateApplication() {
    return new Playground();
}