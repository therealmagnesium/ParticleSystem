#include "Sandbox.h"

int main(int argc, char* argv[])
{
	AppInfo info;
	info.name = "Particle system";
	info.version = "1.0";
	info.author = "Magnus Ahlstromer V";
	info.width = 800;
	info.height = 600;
	info.targetFPS = 60;
	
	Sandbox sandboxApp(info);
	sandboxApp.Run();
	
	return 0;
}