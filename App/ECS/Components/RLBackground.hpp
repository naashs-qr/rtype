/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** RLBackground
*/

#ifndef RLBACKGROUND_HPP_
    #define RLBACKGROUND_HPP_

    #include "ECS/Components/Background.hpp"
    #include "Lib/Raylib/rl-cpp/Textures/Textures.hpp"

namespace ecs {
    typedef Background<::rl::Texture, ::game::Vector2> RLBackground;
};
#endif /* !RLBACKGROUND_HPP_ */

