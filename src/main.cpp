#include <SFML/Graphics.hpp>
// #include <SFML/Graphics/RenderWindow.hpp>
// #include <SFML/Window/WindowHandle.hpp>

// #ifndef UNICODE
// #define UNICODE
// #endif 

// #include <windows.h>

// LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
// {
//     // Register the window class.
//     const wchar_t CLASS_NAME[]  = L"Sample Window Class";
    
//     WNDCLASS wc = { };

//     wc.lpfnWndProc   = WindowProc;
//     wc.hInstance     = hInstance;
//     wc.lpszClassName = CLASS_NAME;

//     RegisterClass(&wc);

//     // Create the window.

//     HWND hwnd = CreateWindowEx(
//         0,                              // Optional window styles.
//         CLASS_NAME,                     // Window class
//         L"Learn to Program Windows",    // Window text
//         WS_OVERLAPPEDWINDOW,            // Window style

//         // Size and position
//         CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

//         NULL,       // Parent window    
//         NULL,       // Menu
//         hInstance,  // Instance handle
//         NULL        // Additional application data
//         );

//     if (hwnd == NULL)
//     {
//         return 0;
//     }

//     ShowWindow(hwnd, nCmdShow);

//     sf::RenderWindow wind(hwnd);
//     // Run the message loop.

//     MSG msg = { };
//     while (GetMessage(&msg, NULL, 0, 0) > 0)
//     {
//         TranslateMessage(&msg);
//         DispatchMessage(&msg);
//     }

//     return 0;
// }

// LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
// {
//     switch (uMsg)
//     {
//     case WM_DESTROY:
//         PostQuitMessage(0);
//         return 0;

//     case WM_PAINT:
//         {
//             PAINTSTRUCT ps;
//             HDC hdc = BeginPaint(hwnd, &ps);

//             // All painting occurs here, between BeginPaint and EndPaint.

//             FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

//             EndPaint(hwnd, &ps);
//         }
//         return 0;

//     }
//     return DefWindowProc(hwnd, uMsg, wParam, lParam);
// }

#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    sf::RenderWindow wind (glfwGetWin32Window(window));
    
    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
