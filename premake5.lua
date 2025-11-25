-- premake5.lua

workspace "text-based-rpg"
    architecture "x86_64"
    startproject "game"

    configurations { "GameDebug", "GameRelease", "GameShipping" }
    platforms { "x64" }

    -- Optionaler Compiler-Switch
    newoption {
        trigger = "cc",
        value = "COMPILER",
        description = "Choose a compiler",
        allowed = {
            { "msc", "Microsoft Visual C++" },
            { "clang", "Clang" },
            { "gcc", "GCC" }
        }
    }

    -- Toolset setzen
    filter "options:cc=msc"
        toolset "msc"
    filter "options:cc=clang"
        toolset "clang"
    filter "options:cc=gcc"
        toolset "gcc"

    -- Globale Settings
    OutputDir = "%{cfg.buildcfg}"
    flags { "MultiProcessorCompile" }

    -- Generelle Build-Konfigurationen
    filter "language:C"
        cdialect "C99"

    filter "configurations:*Debug"
        symbols "On"
        defines { "GAME_DEFINE_DEBUG" }
        runtime "Debug"
        warnings "Extra"

    filter "toolset:gcc or toolset:clang"
        sanitize { "Address" }
        buildoptions { "-mrdseed" }

    filter { "configurations:*Release" }
        optimize "On"
        runtime "Release"
        defines { "GAME_DEFINE_RELEASE" }

    filter "configurations:*Shipping"
        optimize "Full"
        runtime "Release"
        symbols "Off"
        defines { "GAME_DEFINE_RELEASE", "GAME_DEFINE_SHIPPING" }

    -- Plattform-spezifisch
    filter "system:windows"
        systemversion "latest"
        staticruntime "On"
        defines { "_WINDOWS" }

    filter "system:linux"
        defines { "_LINUX" }

project("game")
    kind("ConsoleApp")
    language "C"
    cdialect "C99"
    targetdir ("bin/" .. OutputDir)
    objdir ("build/" .. OutputDir)
    debugdir ("bin/" .. OutputDir)
    implibdir ("libs")

    files {
        "src/**.cpp",
        "src/**.h"
    }

    includedirs { "src/" }
    libdirs { "libs" }
    defines { }
    links { }
