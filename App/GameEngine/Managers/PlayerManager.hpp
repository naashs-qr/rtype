/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** PlayerManager
*/

#ifndef PLAYERMANAGER_HPP_
#define PLAYERMANAGER_HPP_
    #include "GameEngine/Player.hpp"
    #include "GameEngine/Managers/GameManager.hpp"

namespace engine {
namespace rtype {


class PlayerManager {
    private:
        PlayerManager() {

        }
        ~PlayerManager() = default;

    public:
        static PlayerManager &getInstance()
        {
            static PlayerManager instance;
            return (instance);
        }

        void instanciate(int lvl) {
            // if (lvl != 0)
            
            // {
            _players.clear();
            engine::GameManager &gm = engine::GameManager::getInstance();


            _players.push_back(std::make_shared<engine::rtype::ShipPlayer<0>>());

            if (gm._playerNumber > 1)
                _players.push_back(std::make_shared<engine::rtype::ShipPlayer<1>>());
            if (gm._playerNumber > 2)
                _players.push_back(std::make_shared<engine::rtype::ShipPlayer<2>>());
            if (gm._playerNumber > 3)
                _players.push_back(std::make_shared<engine::rtype::ShipPlayer<3>>());
        }

        bool checkLoose() {
            if (_players.size() == 0)
                return (true);
            return (false);
        }

        ecs::Entity getPlayer(unsigned int id) {
            return _players[id]->getEntity();
        }

        std::vector<std::shared_ptr<engine::Entity>> getPlayers() {
            return (_players);
        }

        void removePlayer(unsigned int id) {
            if (_players.size() == 0) {
                return;
            }
            // std::cout << "player--" << std::endl;
            _players.erase(_players.begin() + id);
        }

        std::vector<std::shared_ptr<engine::Entity>> _players;

        // std::vector<
};
}
}

#endif /* !PLAYERMANAGER_HPP_ */
