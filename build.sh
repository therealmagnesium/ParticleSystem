#!/bin/bash

config="$1"
appName="ParticleSystem"

if [[ $config = "run" ]]
then
    mode="$2"
    if [[ $mode = "debug" ]]
    then
        cd "bin/Debug-linux/$appName"
        ./$appName
    elif [[ $mode = "release" ]]
    then
        cd "bin/Release-linux/$appName"
        ./$appName
    elif [[ $mode = "dist" ]]
    then
        cd "bin/Dist-linux/$appName"
        ./$appName
    fi
elif [[ $config = "clean" ]]
then
    rm -rf bin build
else
    vendor/premake/linux/premake5 export-compile-commands
    vendor/premake/linux/premake5 gmake
    make all config=$config -j4
    cp compile_commands/debug.json compile_commands.json
fi
