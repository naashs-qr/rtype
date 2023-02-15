/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** Boss
*/

#ifndef BOOS_HPP_
#define BOOS_HPP_
    #include "GameEngine/Entity.hpp"
    #include "GameEngine/EntityFactory.hpp"
    #include "ECS/Components/Alive.hpp"


namespace engine {

class Boss : public ::engine::Entity {
    public:


        Boss() : ::engine::Entity()
        {

        }
        ~Boss() = default;

        bool update(engine::Boss *boss)
        {
            ecs::Alive &alive = ecs::Coordinator::getInstance().getComponent<ecs::Alive>(this->entity);
            if (alive.dead == true) {
                return false;
            }
            this->action(boss);
            return true;
        }

    

        int nbReps;
        void (*action)(engine::Boss *);


};
}


#endif /* !IBOOS_HPP_ */
