//
// Created by 孙中行 on 25-3-21.
//
#pragma once

#ifdef UE_PLATFORM_WINDOWS
extern Useless::Application* Useless::CreateApplication();
int main(int arc, char** argv){
    printf("Useless Engine Started\n");
    auto app = UselessEngine::CreateApplication();
    if (app) {
        app->Run();
        delete app;
    }
    return 0;
}
#elif defined(UE_PLATFORM_MACOS)

extern Useless::Application* Useless::CreateApplication();

int main(int argc, char** argv) {
    printf("Useless Engine Started\n");

    Useless::Log::Init();
    UE_LOG_CORE_INFO("Core Logger Initialized");
    UE_LOG_INFO("Client Logger Initialized");

    auto app = Useless::CreateApplication();
    if (app) {
        app->Run();
        delete app;
    }
    return 0;
}
#endif