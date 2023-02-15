/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** AnimateSystem
*/


#include "ECS/Systems/AnimateSystem.hpp"

void ecs::AnimateSystem::update(::engine::PollEvent &event) const
{
    for (ecs::Entity const &entity : this->entities) {
        ecs::SpriteAnimation &animation    = Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(entity);
        ecs::RLDrawable &drawable         = Coordinator::getInstance().getComponent<ecs::RLDrawable>(entity);
        animation.actualDelay -= event.dt;
        if (animation.actualDelay <= 0 && !animation.fix) {
            animation.advance();
            drawable.setAnimate(
                animation.container[animation.current.first][animation.current.second]
            );
            animation.actualDelay = animation.delay;
        }
        if (animation.toSet) {
            animation.current = animation.setTo;

            drawable.setAnimate(
                animation.container[animation.current.first][animation.current.second]
            );
            animation.toSet = false;
        }
    }
}