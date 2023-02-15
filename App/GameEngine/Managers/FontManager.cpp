/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** FontManager
*/

#include "GameEngine/Managers/FontManager.hpp"

template<>
void engine::FontManager::unload() {
    for (auto &font : this->_datas) {
        font.second.unload();
    }
}

