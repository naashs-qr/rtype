/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** main
*/

#include "ECS/Coordinator.hpp"
#include "Lib/Raylib/rl-cpp/Windows/Windows.hpp"
#include "GameEngine/EngineButton.hpp"
#include "GameEngine/RLEventHandler.hpp"
#include "GameEngine/Managers/GameManager.hpp"
#include "GameEngine/Initializor.hpp"
#include "GameEngine/GridCollision.hpp"
#include "GameEngine/Square.hpp"
#include "GameEngine/Circle.hpp"
#include "ECS/Components/Hitbox.hpp"
#include "GameEngine/Map/Map.hpp"
#include <iostream>
#include <memory>
//#include <unistd.h> //TODO: Not work on windows
#include <fcntl.h>
#include <cstring>
#include <string>
#include <filesystem>


static void rtype()
{

        if (rl::Keyboard::isKeyPressed(rl::KEY_F11) || rl::Keyboard::isKeyPressed(rl::KEY_F4))
            rl::Window::getInstance().toggleFullscreen();


    engine::PollEvent pollEvent;
    // RL_FlushEvents(RL_FIRSTEVENT, RL_LASTEVENT);
    while (!pollEvent.quit) {
        auto startTime = std::chrono::high_resolution_clock::now();
        pollEvent.playerEvents = {0, 0, 0, 0};

        engine::GameManager::getInstance().loopWindow(pollEvent);

        if (engine::GameManager::getInstance().isSwitching()) engine::GameManager::getInstance().switchWindow();
        auto stopTime = std::chrono::high_resolution_clock::now();
        pollEvent.dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
    }
}

// static void getPaths(std::string const &dirPath)
// {
//     for (const auto & entry : std::filesystem::directory_iterator(dirPath))
//         std::cout << entry.path() << std::endl;
// }


int main(int ac, char **av)
{

    rl::Window::getInstance();
    SetTraceLogLevel(::LOG_WARNING);

    engine::Initializor::init();

    ecs::Coordinator::getInstance();
    engine::GameManager::getInstance();
    // engine::LevelManager::getInstance();

    engine::GridSystem &grid = engine::GridSystem::getInstance(XGRIDSIZE, YGRIDSIZE);
    // engine::Map::getInstance();
    srand(time(NULL));
    rtype();
    std::cout << "End game" << std::endl;
    ::engine::Initializor::destroyer();

    rl::Window::getInstance().close();

    // srand(time(NULL));

    // engine::Map theMap;
    // theMap.generate(11, 150, "level0", "boss10");
    // theMap.debugAll();
    // theMap.debugFill("Assets/Map/Default.fill");

    // FILE *infile;

    // infile = fopen ("Assets/Map/Default-copy.map", "r");
    // std::vector<std::pair<int, int>> pairs;
    // std::pair<int, int> pair;
    // while(fread(&pair, sizeof(std::pair<int, int>), 1, infile) != 0) {
    //     pairs.push_back(pair);
    // }
    
    // fclose(infile);
    
    // // std::vector<int> tmp;
    // // int tmp = 0;
    // int idxMax = 0;
    // for (size_t  i = 1; i < pairs.size(); ++i) {
    //     if (pairs[i].second >= pairs[idxMax].second) {
    //         idxMax = i;
    //     } 
    //     // tmp.push_back(pairs[i].second);
    // }
    // pairs[idxMax].second -= 2;
    // FILE *outfile;

    // outfile = fopen ("Assets/Map/Default.map", "w");
    // for (auto pair : pairs) {
    //     fwrite(&pair, sizeof(std::pair<int, int>), 1, outfile);
    // }
    // fclose (outfile);

    // theMap.debugMap("Assets/Map/Default.map");


    return (0);
}

    

