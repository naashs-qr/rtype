/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** Particles
*/

#ifndef RLPARTICLE_HPP_
#define RLPARTICLE_HPP_

    #include "ECS/Components/Particles.hpp"
    #include "Utils/Vector2.hpp"
    #include "Utils/Rect.hpp"
    #include "Lib/Raylib/rl-cpp/Shaders/Particles/Particles.hpp"


namespace ecs {
    typedef Particles<std::vector<::rl::Particle>, ::game::Vector2> RLParticles;
};


#endif /* !PARTICLES_HPP_ */
