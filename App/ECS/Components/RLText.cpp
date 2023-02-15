/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** RLText
*/


#include "ECS/Components/RLText.hpp"

template<>
void ecs::RLText::draw(const game::Vector2 &position)
{
    _text.position = position;
 
    _text.draw();
}

template<>
void ecs::RLText::swap(rl::Text text)
{
    _text = text;
}

