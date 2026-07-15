#include <loaders/ShaderLoader.h>
#include <fstream>
#include <sstream>
#include <logger/Logger.h>

engine::ShaderSource engine::ShaderLoader::Load(const ShaderDesc& desc) {
    ShaderSource source;
    source.vertexCode   = readFile(desc.vertexPath);
    source.fragmentCode = readFile(desc.fragmentPath);
    return source;
}

std::string engine::ShaderLoader::readFile(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        CORE_ERROR("Failed to open file");
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}