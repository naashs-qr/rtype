/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** Map
*/

#include "GameEngine/Map/Map.hpp"
#include "GameEngine/Managers/LevelManager.hpp"

void engine::Map::run(float dt) {
    static int check = 0;
    static int wTrig = WALLXSIZE;
    this->distance +=  100 * dt; // * baseScroll speed
    engine::Boss *boss = static_cast<engine::Boss *> (engine::LevelManager::getInstance().getBossPtr().get());
    if (this->distance >= this->bossTrigger && boss->nbReps == -1) {
        // std::cout << "BOSS TRIGGER" << std::endl;
        boss->nbReps = 0;
    }
    if (this->distance > wTrig && !this->walls.empty()) {
        std::pair<int, int> pair = this->walls.front();
        ::game::Vector2 pos(1920, 0);

        engine::Wall upWall(pos, pair.first);

        pos.y = 1080 - 100 * pair.second;
        engine::Wall downWall(pos, pair.second);
        // std::cout << "spawned walls" << std::endl;

        wTrig += WALLXSIZE;
        this->walls.pop();
    }
    // std::cout << this->distance << std::endl;
    while(!toSpawn.empty()) {
        engine::SpawnElement &elem = toSpawn.front();
        if (elem.distance <= this->distance ) {
            engine::Spawner spawner;
            if (elem.delay > 0) {
                spawner.addDelay(elem.delay);
            }
            spawner.setPos(elem.pos);
            spawner.setType(elem.entityType);              
            spawner.setReps(elem.repeat);
            // std::cout << elem.repeat << std::endl;
            // spawner.setRepType(elem.repeatType);
            this->toSpawn.pop();
        } else {
            break;
        }
    }
}