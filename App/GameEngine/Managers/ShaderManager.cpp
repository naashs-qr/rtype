/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** ShaderManager
*/


#include "GameEngine/Managers/ShaderManager.hpp"

template<>
void engine::ShaderManager::unload() {
    for (auto &shader : this->_datas) {
        shader.second.unload();
    }
}

