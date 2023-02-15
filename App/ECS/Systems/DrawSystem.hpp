/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** DrawSystem
*/

#ifndef DRAWSYSTEM_HPP_
    #define DRAWSYSTEM_HPP_

    #include "ECS/System.hpp"

    #include "ECS/Components/RLDrawable.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {
class DrawSystem : public ASystem {
    public:
        DrawSystem() = default;
        ~DrawSystem() = default;

        void update(::engine::PollEvent &event) const final;
};
}

#endif /* !DRAWSYSTEM_HPP_ */
