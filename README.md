No build system, yet, all you need to do is clone and compile.

All your code should be in the app folder, your "EntryPoint" is ExampleLayer.h. Code that should be executed before the main loop is inside of "Start()" and code that should be executed inside of the main loop is in "OnUpdate()" make sure to always call m_CoastalRenderer.Renderer() as the last thing inside of "OnUpdate()". As this is a young API, no official documentation is released, but when it is it will be linked in the readme.

Happy Programming!
