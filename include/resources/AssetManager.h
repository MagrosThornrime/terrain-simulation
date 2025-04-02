#pragma once

#include <iostream>
#include <map>

#include <rendering/Texture.h>
#include <rendering/Shader.h>
#include <Logger.h>
#include <resources/FileIO.h>


class AssetManager{
    std::map<std::string, Texture> textures;
    std::map<std::string, Shader> shaderPrograms;

    void loadProgramCode(const std::string& path, std::string& code);
    Image loadImage(const std::string &path, ImageType imageType, bool bFlipped);

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