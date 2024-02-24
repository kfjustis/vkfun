cmake_minimum_required(VERSION 3.22)
project(vkfun)

set(CMAKE_CXX_STANDARD 11)

set(SRC main.cpp)
add_executable(${PROJECT_NAME} ${SRC})

# Find and link GLFW.
find_package(glfw3 3.3 REQUIRED)
target_link_libraries(${PROJECT_NAME} glfw)

# Note:
# Per https://www.glfw.org/docs/3.3/build_guide.html, no need to
# specifically target_include_directories. The includes are already
# in `glfw`.

# Find and link GLM.
find_package(glm REQUIRED)
target_link_libraries(${PROJECT_NAME} glm::glm)

# Find and link Vulkan.
find_package(Vulkan REQUIRED)
target_link_libraries(${PROJECT_NAME} ${Vulkan_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${Vulkan_INCLUDE_DIR})