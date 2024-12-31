cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    # GIT_TAG 2.6.2
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

include(FetchContent)
FetchContent_Declare(glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(glfw)

add_executable(main src/main.cpp)
# add_executable(main WIN32 src/main.cpp)
# set_target_properties(main PROPERTIES WIN32_EXECUTABLE)
# target_link_libraries(main PRIVATE SFML::Graphics glfw)
target_link_libraries(main PRIVATE sfml-graphics glfw)
