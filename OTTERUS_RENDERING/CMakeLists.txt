cmake_minimum_required(VERSION 3.26)
project(OTTERUS_RENDERING)

add_library(${PROJECT_NAME} STATIC
        src/Camera.cpp
        src/GraphicsEngine.cpp
        src/FrameBuffer.cpp
        src/Shader.cpp
        src/ShaderLoader.cpp
        src/Texture.cpp
        src/TextureLoader.cpp
        src/Mesh.cpp
        src/MeshLoader.cpp
        src/stb_img.cpp
        src/TinyObjLoader.cpp
        src/Transform.cpp
)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/vendor/stb
        ${CMAKE_SOURCE_DIR}/vendor/tiny_obj_loader
)

target_link_libraries(OTTERUS_RENDERING
        PUBLIC
        glad
        glfw
        glm::glm
        OTTERUS_LOGGER
)