/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** RLParticles
*/

#include "ECS/Components/RLParticles.hpp"
#include "ECS/Coordinator.hpp"
#include "GameEngine/RType/Particles/Propulsion.hpp"

template<>
void ecs::RLParticles::draw()
{
    for (std::vector<rl::Particle>::iterator obj = _particles.begin(); obj < _particles.end(); obj++) {
        (*obj).draw();
    }
}

template<>
void ecs::RLParticles::update(ecs::Entity ent, float dt)
{
    this->upd(ent, _particles, dt);
}

