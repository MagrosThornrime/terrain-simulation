#pragma once

#include <iostream>
#include <unordered_map>

#include <rendering/Texture.h>
#include <rendering/Shader.h>
#include <Logger.h>
#include <resources/FileIO.h>


class AssetManager{
    std::unordered_map<std::string, Texture> _textures;
    std::unordered_map<std::string, Shader> _shaderPrograms;

    void _loadProgramCode(const std::string& path, std::string& code);
    Image _loadImage(const std::string &path, ImageType imageType, bool bFlipped);

public:

    AssetManager();

    void loadShader(const std::string& vertexPath, const std::string& fragmentPath,
                           const std::string& name);
    void loadShader(const std::string& vertexPath, const std::string& fragmentPath,
                           const std::string& geometryPath, const std::string& name);
    Shader* getShader(const std::string& name);

    void loadTexture(const std::string& path, ImageType imageType, bool bFlipped,
                     TextureParameters textureParameters, const std::string& name);
    Texture* getTexture(const std::string& name);

    ~AssetManager();

};