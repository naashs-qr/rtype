/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** SDLBackground
*/

#ifndef SDLBACKGROUND_HPP_
    #define SDLBACKGROUND_HPP_

    #include "ECS/Components/Background.hpp"
    #include "Lib/SDL/Sprite.hpp"

namespace ecs {
    typedef Background<::lib::sdl::Sprite, game::Vector2> SDLBackground;
};
#endif /* !SDLBACKGROUND_HPP_ */

