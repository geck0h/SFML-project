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

        postbuildcommands
        {
            "{COPYFILE} %[%{wks.location}dlls/Debug/sfml-system-d-3.dll] %[%{wks.location}bin/" .. outputdir .. "/sfml-system-d-3.dll]",
            "{COPYFILE} %[%{wks.location}dlls/Debug/sfml-graphics-d-3.dll] %[%{wks.location}bin/" .. outputdir .. "/sfml-graphics-d-3.dll]",
            "{COPYFILE} %[%{wks.location}dlls/Debug/sfml-audio-d-3.dll] %[%{wks.location}bin/" .. outputdir .. "/sfml-audio-d-3.dll]",
            "{COPYFILE} %[%{wks.location}dlls/Debug/sfml-network-d-3.dll] %[%{wks.location}bin/" .. outputdir .. "/sfml-network-d-3.dll]",
            "{COPYFILE} %[%{wks.location}dlls/Debug/sfml-window-d-3.dll] %[%{wks.location}bin/" .. outputdir .. "/sfml-window-d-3.dll]"
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

        postbuildcommands
        {
            "{COPYFILE} %[%{wks.location}dlls/Release/sfml-system-3.dll] %[%{wks.location}bin/" .. outputdir .. "/sfml-system-3.dll]",
            "{COPYFILE} %[%{wks.location}dlls/Release/sfml-graphics-3.dll] %[%{wks.location}bin/" .. outputdir .. "/sfml-graphics-3.dll]",
            "{COPYFILE} %[%{wks.location}dlls/Release/sfml-audio-3.dll] %[%{wks.location}bin/" .. outputdir .. "/sfml-audio-3.dll]",
            "{COPYFILE} %[%{wks.location}dlls/Release/sfml-network-3.dll] %[%{wks.location}bin/" .. outputdir .. "/sfml-network-3.dll]",
            "{COPYFILE} %[%{wks.location}dlls/Release/sfml-window-3.dll] %[%{wks.location}bin/" .. outputdir .. "/sfml-window-3.dll]"
        }

        
    filter {}


