local outputdir = "%{cfg.buildcfg}-%{cfg.system}"

project("ParticleSystem")
kind("ConsoleApp")
language("C++")

targetdir("../bin/" .. outputdir .. "/%{prj.name}")
objdir("../build/" .. outputdir .. "/%{prj.name}")

files({
    "source/**.h",
    "source/**.cpp",
})

includedirs({
    "../Engine/source",
})

libdirs({
    "../bin/" .. outputdir .. "/Engine",
})

defines({})

links({
    "Engine",
    "sfml-graphics",
    "sfml-window",
    "sfml-system",
})

postbuildcommands({
    "cp -r assets/ %{cfg.buildtarget.directory}",
})

filter("system:Unix")
system("linux")
cppdialect("C++17")
systemversion("latest")
defines({
    "PLATFORM_LINUX",
})

filter("configurations:Debug")
defines("DEBUG")
symbols("on")

filter("configurations:Release")
defines("RELEASE")
optimize("on")

filter("configurations:Dist")
defines("DIST")
optimize("on")
