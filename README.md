# Media extensions sample

This is an attempt to add Windows Universal projects to the C#/C++ sample published by MS at https://code.msdn.microsoft.com/windowsapps/Media-extensions-sample-7b466096

The goal for this project is to develop Windws Universal versions of all the Media Foundation Transform Extensions using Windows Runtime Component project types. So no DLL project types or it's typical dllmain.cpp, *.idl, *.def, or targetver.h files.

New projects:
- MediaExtension.Universal: A UWP App. This works with the Windows 8.1 Runtime Components in Media Extensions.
- GrayscaleTransform.Universal: An attempt to create a C++ Windows Runtime Component project using the shared code from GrayscaleTransform.Shared project. This Windows Runtime Component doesn't work.

To load and run these projects, you must use Visual Studio 2015 since Visual Studio 2013 does not support Windows 10 Universal projects and Visual Studio 2017 does not support Windows 8.1 project types. Visual Studio 2015 is the only version that supports both forms for Windows Runtime Components.

