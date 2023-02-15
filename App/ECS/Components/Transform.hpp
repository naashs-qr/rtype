/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** Transform
*/

#ifndef TRANSFORM_HPP_
    #define TRANSFORM_HPP_
    
    #include "Utils/Vector2.hpp"
    #include "ECS/Entity.hpp"


namespace ecs {
    struct Transform {
        game::Vector2 position;
        float rotation;
        float scale;
    };
};

#endif /* !TRANSFORM_HPP_ */
