/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** ShaderSystem
*/

#ifndef SHADERSYSTEM_HPP_
#define SHADERSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"
    #include "ECS/Components/Shoot.hpp"
    #include "ECS/Components/Transform.hpp"
    

namespace ecs {

    class ShaderSystem : public ASystem {
        public:
            ShaderSystem() = default;
            ~ShaderSystem() = default;

            void update(::engine::PollEvent &event) const final;
            

    };
}

#endif /* !SHADERSYSTEM_HPP_ */

