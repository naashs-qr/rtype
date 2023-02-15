/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** PollEvent
*/

#ifndef POLLEVENT_HPP_
    #define POLLEVENT_HPP_

    #include <map>
    #include <array>
    #include <vector>

namespace engine {
enum Event {
    NONE        = 0,
    UP          = 1,
    DOWN        = 2,
    LEFT        = 4,
    RIGHT       = 8,
    SEC_UP      = 16,
    SEC_DOWN    = 32,
    SEC_LEFT    = 64,
    SEC_RIGHT   = 128,
    SHOOT       = 256,
    INTERACT    = 512,
    PAUSE       = 1024,
    MENU        = 2048,
    // ATTACH      = 4096,
    QUIT        = 4096
};

struct PlayerEvent {
    unsigned short pressed;
    unsigned short released;
};

struct PollEvent {
    PollEvent() {
        this->dt = 0;
        this->playerEvents[0] = {0, 0};
        this->playerEvents[1] = {0, 0};
        this->playerEvents[2] = {0, 0};
        this->playerEvents[3] = {0, 0};
        this->quit = false;
    }

    
    std::array<PlayerEvent, 4> playerEvents;
    float dt;
    bool quit;
};
} // namespace engine

#endif /* !POLLEVENT_HPP_ */
