/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** Shader
*/

#ifndef ENGINE_SHADER_HPP_
    #define ENGINE_SHADER_HPP_

    #include "GameEngine/Entity.hpp"
namespace engine {
    class Shader : public engine::Entity {
        public:
            Shader() : Entity() {
                
            }
            ~Shader() = default;

            virtual void addShaderedEntity(ecs::Entity entity) = 0;


            virtual void removeShaderedEntity(ecs::Entity entity) = 0;
    };
} // engine

#endif /* !SHADER_HPP_ */
