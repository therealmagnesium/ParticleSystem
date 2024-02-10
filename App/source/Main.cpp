#include "Sandbox.h"

int main(int argc, char* argv[])
{
    AppInfo info;
    info.name = "Particle system";
    info.version = "1.4-dev";
    info.author = "Magnus Ahlstromer V";
    info.windowWidth = 1280;
    info.windowHeight = 720;
    info.targetFPS = 120;

    Sandbox sandboxApp(info);
    sandboxApp.Run();

    return 0;
}
