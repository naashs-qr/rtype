/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** Selector
*/

#ifndef SELECTOR_HPP_
    #define SELECTOR_HPP_

    
    #include "Utils/Vector2.hpp"
    #include "ECS/Entity.hpp"


namespace ecs {
    struct Selector {
        Entity selected;
    };
};


#endif /* !SELECTOR_HPP_ */
