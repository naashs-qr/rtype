/*
** EPITECH PROJECT, 2022
** Rtype
** File description:
** RType-MultiBullet
*/

#ifndef MULTIBULLET_ENEMY_HPP_
    #define MULTIBULLET_ENEMY_HPP_

    #include "GameEngine/Projectile.hpp"
    #include "GameEngine/RType/Particles/Propulsion.hpp"
    #include "GameEngine/RType/Shoot/Movement.hpp"
    #include "GameEngine/Square.hpp"
    #include "Utils/Vector2.hpp"
    

namespace engine {
namespace rtype {


class MultiBullet : public ::engine::Projectile {
    public:
        void setPos(game::Vector2 pos) {
            ::ecs::Transform &trans = ecs::Coordinator::getInstance().getComponent<::ecs::Transform>(this->entity);
            trans.position.x = pos.x;
            trans.position.y = pos.y;
        }

        void setAngle(float angle) {
            ::ecs::Transform &trans = ecs::Coordinator::getInstance().getComponent<::ecs::Transform>(this->entity);
            trans.rotation = angle; // TODO: faudrait prendre ca en compte un jour :)
        }

        static ecs::Entity construct() {
            ::engine::rtype::MultiBullet projectile;
            return projectile.entity;
        }

        static ::ecs::Entity fire(::game::Vector2 &pos, short lvl, ::game::Vector2 target, ecs::CollisionType type) {
            ::engine::rtype::MultiBullet projectile1(type, 0);
            projectile1.setPos(::game::Vector2(pos.x - 50, pos.y));
            ::engine::rtype::MultiBullet projectile2(type, 1);
            projectile2.setPos(::game::Vector2(pos.x - 50, pos.y+40));
            ::engine::rtype::MultiBullet projectile3(type, 2);
            projectile3.setPos(::game::Vector2(pos.x - 50, pos.y +80));

            ::engine::rtype::MultiBullet projectile4(type, 3);
            projectile4.setPos(::game::Vector2(pos.x + 150, pos.y - 30));
            ::engine::rtype::MultiBullet projectile5(type, 4);
            projectile5.setPos(::game::Vector2(pos.x + 150, pos.y + 250));

            ::engine::rtype::MultiBullet projectile6(type, 5);
            projectile6.setPos(::game::Vector2(pos.x + 500, pos.y));
            ::engine::rtype::MultiBullet projectile7(type, 6);
            projectile7.setPos(::game::Vector2(pos.x + 500, pos.y + 40));
            ::engine::rtype::MultiBullet projectile8(type, 7);
            projectile8.setPos(::game::Vector2(pos.x + 500, pos.y +80));



            (void)lvl;
            return projectile1.entity;
        }



        MultiBullet(ecs::CollisionType type = ecs::CollisionType::COL_PROJECTILE_ENEMY, int bullet = 0, ::game::Vector2 pos = {0, 0}) : ::engine::Projectile(pos)
        {
            ::ecs::Coordinator::getInstance().addComponent(
                this->entity, 
                ecs::RLDrawable {
                    SpriteManager::getInstance().getData(SpriteType::SPR_RTYPE3), false
                }
            );

            ecs::CollisionType col = ecs::CollisionType::COL_PROJECTILE_ENEMY;
                
          
            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::Alive {
                    .hp = 100,
                    .dead = false,
                    .shield = false
                }
            );
            std::vector<game::Vector2> vect = {::game::Vector2(-200, -100), ::game::Vector2(-200, 0), ::game::Vector2(-200, 100), 
                ::game::Vector2(0, -200), ::game::Vector2(0, 200), ::game::Vector2(200, -100), ::game::Vector2(200, 0), ::game::Vector2(200, 100)};
            ecs::RLDrawable &drawable = ecs::Coordinator::getInstance().getComponent<ecs::RLDrawable>(this->entity);
            ecs::RigidBody &body = ecs::Coordinator::getInstance().getComponent<ecs::RigidBody>(this->entity);
            body.velocity = vect[bullet];
            drawable._drawable.setSize(::game::Vector2(drawable._drawable.getSize() * 2.0));
            ecs::SpriteAnimation anim;
            anim.max = {{0, 4}};

            anim.container = {
                {0, {game::Rect(228*2.0, 452*2.0, 18*2.0, 17*2.0), game::Rect(246*2.0, 449*2.0, 18*2.0, 17*2.0), game::Rect(265*2.0, 449*2.0, 18*2.0, 17*2.0), game::Rect(283*2.0, 449*2.0, 18*2.0, 17*2.0)}},
            };
            anim.current = {0, 0};
            anim.delay = 0.1;
            anim.actualDelay = 0.1;
            anim.fix = false;
            anim.toSet = true;
            anim.setTo = {0, 0};
            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                anim
            );

            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::Hitbox {
                    .type = ecs::HitBoxType::BOX_SQUARE,
                    .bounds = std::make_shared<engine::Square>(
                        engine::Square(
                            pos, 
                            anim.container.at(anim.current.first)[anim.current.second].w,
                            anim.container.at(anim.current.first)[anim.current.second].h
                    )),
                    .collidesWith = {},
                    .colType = col,
                    .invFrames = 0,
                    .rect = rl::Rectangle(
                        0,
                        0,
                        anim.container.at(anim.current.first)[anim.current.second].w,
                        anim.container.at(anim.current.first)[anim.current.second].h
            )});
            
            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::Bullet {
                    .update = &engine::rtype::Movement::updateStraight
                }
            );
            
        };

        ~MultiBullet() = default;
};
}; // rtype
} // engine

#endif