#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <Engine/Window.h>
#include <Engine/Util.h>

int main() {
    std::cout << "Hello, World!" << std::endl;

    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    Window *window = new Window();

    if (!window->Initialise(800, 600, "ARPG", true))
    {
        glfwTerminate();
        return -1;
    }

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::cout << "Failed to intialise GLAD." << std::endl;
        return -1;
    }

    glClearColor(0.2, 0.2, 0.2, 1);

    Util::Log("Test Log");

    while (!window->ShouldClose())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();
        window->SwapBuffers();
    }

    window->Close();

    Util::SuccessExit();
}