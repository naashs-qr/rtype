/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** BackButton
*/

#ifndef BACKBUTTON_HPP_
    #define BACKBUTTON_HPP_

    #include "ECS/Entity.hpp"
    #include "ECS/Coordinator.hpp"
    #include "GameEngine/Managers/SpriteManager.hpp"


namespace engine {
    namespace rtype {
        class BackButton {
            private:
                BackButton(::ecs::Entity, ::ecs::Entity);
                ::ecs::Entity entity;  

            public:
                static ::ecs::Entity construct(::ecs::Entity prev = ::ecs::MAX_ENTITIES + 1, ::ecs::Entity first = ::ecs::MAX_ENTITIES + 1) {
                    BackButton button(prev, first);
                    return (button.entity);
                }

                static ::ecs::Entity click(ecs::Entity entity);
                static void hover(ecs::Entity);
                static void resetHover(ecs::Entity);

        };
    };
};


#endif /* !BACKBUTTON_HPP_ */
