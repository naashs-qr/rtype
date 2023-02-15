/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** GameEntities
*/

#ifndef GAMEENTITIES_HPP_
    #define GAMEENTITIES_HPP_

    #include "GameEngine/IEntity.hpp"
    #include "GameEngine/Entity.hpp"

namespace engine {
    // enum GameEntitiesType {
    //     PLAYER,
    //     ENEMY,
    //     PROJECTILE_ALLY,
    //     PROJECTILE_ENEMY,
    //     WALL,
    //     PICKUP,
    //     TRIGGER,
    //     MAX_GAME_ENTITIES
    // };

    class GameEntities
    {
        private:
            GameEntities() = default;
            ~GameEntities() = default;

            std::map<ecs::Entity, std::shared_ptr<engine::IEntity>> _entities;

        public:
            static GameEntities &getInstance()
            {
                // std::cout << "GameEntities" << std::endl;
                static GameEntities instance;
                return (instance);
            }

            void addEntity(std::shared_ptr<engine::IEntity> gameEntity)
            {
                // std::cout << "GameEntities addEntity" << std::endl;
                this->_entities[gameEntity.get()->getEntity()] = gameEntity;
            }

            std::shared_ptr<engine::IEntity> &getEntity(ecs::Entity entity)
            {
                return (this->_entities[entity]);
            }
    };
        

}

#endif /* !GAMEENTITIES_HPP_ */
