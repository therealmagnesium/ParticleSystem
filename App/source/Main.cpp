#include "Sandbox.h"

int main(int argc, char* argv[])
{
    AppInfo info;
    info.name = "Particle system";
    info.version = "1.1-dev";
    info.author = "Magnus Ahlstromer V";
    info.windowWidth = 800;
    info.windowHeight = 600;
    info.targetFPS = 480;

    Sandbox sandboxApp(info);
    sandboxApp.Run();

    return 0;
}
