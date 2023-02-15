/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** MovementSystem
*/

#ifndef MOVEMENTSYSTEM_HPP_
    #define MOVEMENTSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {

    class MovementSystem : public ASystem {
        public:
            MovementSystem() = default;
            ~MovementSystem() = default;

            void update(::engine::PollEvent &event) const final;

    };
}
#endif /* !MOVEMENTSYSTEM_HPP_ */
