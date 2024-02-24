#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <iostream>

int main(void) {
    // Initialize GLFW instance and set up a window.
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow* window = glfwCreateWindow(800, 600, "vkfun", nullptr, nullptr);

    // Query and print Vulkan extensions count for the machine.
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::cout << extensionCount << " extensions supported\n";

    // Verify glm library works.
    glm::mat4 matrix;
    glm::vec4 vec;
    auto test = matrix * vec;

    // Run the window until closed.
    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    // Clean up window and GLFW instance.
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}