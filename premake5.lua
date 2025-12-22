workspace("SFML-project")
    configurations{ "DebugDLL", "ReleaseDLL" }
    platforms{ "x64" }
    language("C++")
    cppdialect("C++17")

outputdir = "%{cfg.platform}/%{cfg.buildcfg}"

project("SFML-project")
    kind("ConsoleApp")
    location("SFML-project")

    targetdir("bin/" .. outputdir)
    objdir("bin/int/" .. outputdir)

    files
    {
        "%{prj.name}/src/*.cpp",
        "%{prj.name}/src/*.h",
    }

    includedirs
    {
        "dep/SFML/include"
    }

    libdirs
    {
        "dep/SFML/lib"
    }

    filter { "platforms:x64", "configurations:DebugDLL" }
        defines { "_DEBUG", "_CONSOLE", "_UNICODE", "UNICODE" }
        system ("Windows")
        architecture ("x86_64")
        runtime("Debug")

        links
        {
            "sfml-system-d.lib",
            "sfml-graphics-d.lib",
            "sfml-audio-d.lib",
            "sfml-network-d.lib",
            "sfml-window-d.lib"
        }

    filter { "platforms:x64", "configurations:ReleaseDLL" }
        defines { "NDEBUG", "_CONSOLE", "_UNICODE", "UNICODE" }
        system ("Windows")
        architecture ("x86_64")
        runtime("Release")
        optimize ("on")

        links
        {
            "sfml-system.lib",
            "sfml-graphics.lib",
            "sfml-audio.lib",
            "sfml-network.lib",
            "sfml-window.lib"
        }
        
    filter {}


