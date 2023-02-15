/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** Title
*/

#ifndef TITLE_HPP_
#define TITLE_HPP_
    #include "GameEngine/Entity.hpp"
    #include "GameEngine/Managers/FontManager.hpp"
    #include "GameEngine/Managers/SpriteManager.hpp"


namespace engine {
namespace rtype {
class Title : public ::engine::Entity {
    public:
        Title() : engine::Entity() {
            ::ecs::Coordinator::getInstance().addComponent(
                this->entity, 
                ecs::Transform {
                    .position = {500.0, 50.0},
                    .rotation = 0.0,
                    .scale = 1.0
                }
            );
            ::ecs::Coordinator::getInstance().addComponent(
                this->entity, 
                ecs::RLDrawable {
                    SpriteManager::getInstance().getData(SpriteType::SPR_TITLE), false
                }
            );
            ecs::RLDrawable &Drawable = ecs::Coordinator::getInstance().getComponent<ecs::RLDrawable>(entity);
            Drawable._drawable.setSize(::game::Vector2(Drawable._drawable.getSize() * 1.0));
            // ecs::RLDrawable &draw = ecs::Coordinator::getInstance().getComponent<ecs::RLDrawable>(this->entity);
            // draw.setSize(game::Vector2(117, 79));
            ecs::SpriteAnimation anim;
            anim.max = {{0, 1}};
            anim.container = {
                {0, {game::Rect(0, 0, 900, 100)}}
            };
            anim.current = {0, 0};
            anim.delay = 0.2;
            anim.actualDelay = 0.2;
            anim.fix = true;
            anim.toSet = true;
            anim.setTo = {0 , 0};
            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                anim
            );

        }
        ~Title() = default;

    protected:
    private:
};
} // namespace rtype
} // namespace engine

#endif /* !TITLE_HPP_ */
