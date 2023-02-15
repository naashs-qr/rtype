/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** LeaderBoard
*/

#ifndef LEADERBOARD_HPP_
#define LEADERBOARD_HPP_
    #include "GameEngine/Entity.hpp"
    #include "GameEngine/Managers/FontManager.hpp"
    #include "GameEngine/Managers/SpriteManager.hpp"


namespace engine {
namespace rtype {
class LeaderBoard : public ::engine::Entity {
    public:
        LeaderBoard() : engine::Entity() {
            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::RLText(
                    ::rl::Text("Loading for next level", 
                        ::rl::Font(engine::FontManager::getInstance().getData(engine::FontType::FONT_BOLD)), 
                        35, 
                        ::rl::Color(255, 255, 255, 255), 
                        ::rl::Vector2(680, 900)),
                    0
                )
            );
            ::ecs::Coordinator::getInstance().addComponent(
                this->entity, 
                ecs::Transform {
                    .position = {0, 0},
                    .rotation = 0.0,
                    .scale = 1.0
                }
            );

        }
        ~LeaderBoard() = default;

    protected:
    private:
};
} // namespace rtype
} // namespace engine

#endif /* !LeaderBoard_HPP_ */
