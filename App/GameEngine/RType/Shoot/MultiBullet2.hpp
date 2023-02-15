/*
** EPITECH PROJECT, 2022
** Rtype
** File description:
** RType-MultiBullet
*/

#ifndef MULTIBULLET2_ENEMY_HPP_
    #define MULTIBULLET2_ENEMY_HPP_

    #include "GameEngine/Projectile.hpp"
    #include "GameEngine/RType/Particles/Propulsion.hpp"
    #include "GameEngine/RType/Shoot/Movement.hpp"
    #include "GameEngine/RType/Shoot/RaygunEnemy.hpp"
    #include "GameEngine/RType/Shoot/Projectile.hpp"


    #include "GameEngine/Square.hpp"
    #include "Utils/Vector2.hpp"
    

namespace engine {
namespace rtype {


class MultiBullet2 : public ::engine::Projectile {
    public:
        

        static ::ecs::Entity fire(::game::Vector2 &pos, short lvl, ::game::Vector2 target, ecs::CollisionType type) {
            ::engine::rtype::RaygunEnemy::fire(pos, 0, target, type);
            return (::engine::rtype::RaygunEnemy::fire(pos, 1, target, type));
            



            (void)lvl;
            // return projectile1.entity;
        }

       
};
}; // rtype
} // engine

#endif