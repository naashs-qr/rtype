/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** SelectorSystem
*/

#ifndef SELECTORSYSTEM_HPP_
    #define SELECTORSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"
    #include "ECS/Components/Control.hpp"
    

namespace ecs {

    class SelectorSystem : public ASystem {
        public:
            SelectorSystem() = default;
            ~SelectorSystem() = default;

            void update(::engine::PollEvent &event) const final;

    };
}
#endif /* !SELECTORSYSTEM_HPP_ */
