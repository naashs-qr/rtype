/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** ShaderManager
*/

#ifndef SHADERMANAGER_HPP_
#define SHADERMANAGER_HPP_
    #include "Utils/DataManager.hpp"
    #include "Lib/Raylib/rl-cpp/Shaders/Shader.hpp"

namespace engine {
enum ShaderType {
    SHADER_WAVE, 
    SHADER_SPOTLIGHT,
    SHADER_COLOR,
    SHADER_RAIN,
    SHADER_GALAXY,
};
typedef DataManager<::rl::Shader, ShaderType> ShaderManager;
};

#endif /* !SHADERMANAGER_HPP_ */
