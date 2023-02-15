/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** SpriteManager
*/


#include "GameEngine/Managers/SpriteManager.hpp"

template<>
void engine::SpriteManager::unload() {
    for (auto &sprite : this->_datas) {
        sprite.second.unload();
    }
}

