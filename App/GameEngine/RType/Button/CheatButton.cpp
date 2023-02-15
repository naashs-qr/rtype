/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** CheatButton
*/


#include "GameEngine/RType/Button/CheatButton.hpp"
#include "GameEngine/RType/Button/JoinButton.hpp"
#include "GameEngine/RType/Button/SoloButton.hpp"
#include "GameEngine/RType/Button/QuitButton.hpp"
#include "GameEngine/RType/Button/BackButton.hpp"
#include "GameEngine/RType/Button/SettingsBackButton.hpp"
#include "GameEngine/Managers/FontManager.hpp"
#include "GameEngine/Managers/SettingsManager.hpp"
#include "GameEngine/EngineButton.hpp"
#include "Lib/Raylib/rl-cpp/Texts/Texts.hpp"


engine::rtype::CheatButton::CheatButton(::ecs::Entity prev = ::ecs::MAX_ENTITIES + 1)
{
    this->entity = ::ecs::Coordinator::getInstance().createEntity();
    ecs::Entity next = engine::rtype::SettingsBackButton::construct(this->entity, prev);
    engine::rtype::SettingsManager &settings = engine::rtype::SettingsManager::getInstance();
    ::ecs::Coordinator::getInstance().addComponent(
        this->entity, 
        ecs::Transform {
            .position = {855.0, 500.0},
            .rotation = 0.0,
            .scale = 1.0
        }
    );
    ::ecs::Coordinator::getInstance().addComponent(
        this->entity, 
        ecs::RLDrawable {
            SpriteManager::getInstance().getData(SpriteType::SPR_BUTTON), false
        }
    );
    ecs::RLDrawable &Drawable = ecs::Coordinator::getInstance().getComponent<ecs::RLDrawable>(entity);
    Drawable._drawable.setSize(::game::Vector2(Drawable._drawable.getSize() * 2.0));
    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        ecs::RLText(
            ::rl::Text("Cheat", 
                ::rl::Font(FontManager::getInstance().getData(FontType::FONT_BOLD)), 
                35, 
                ::rl::Color(255, 255, 255, 255), 
                ::rl::Vector2(925, 560)),
            1
        )
    );
    ecs::SpriteAnimation anim;
    anim.max = {{0, 2}, {1, 2}};
    anim.container = {
        {0, {game::Rect(234, 0, 234, 158), game::Rect(234, 158, 234, 158)}},
        {1, {game::Rect(0, 0, 234, 158), game::Rect(0, 158, 234, 158)}}
    };
    anim.current = {0, 0};
    anim.delay = 0.2;
    anim.actualDelay = 0.2;
    anim.fix = true;
    anim.toSet = true;
    anim.setTo = {settings.cheat, 0};
    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        anim
    );
    // ecs::RLText &Text = ecs::Coordinator::getInstance().getComponent<ecs::RLText>(entity);
    // Text.setText("Multis", "Assets/Fonts/Digital-Serial-Bold.ttf", 30, {255, 255, 255});

    ::ecs::Coordinator::getInstance().addComponent(
        this->entity, 
        ecs::Button {
            .click = &CheatButton::click,
            .hover = &CheatButton::hover,
            .resetHover = &CheatButton::resetHover,
            .next = next,
            .isHover = false,
            .isClic =  false,
            .isEsc = false,
            .prev = prev,
            .dead = false,
            .listID = 1
        }
    );
}

::ecs::Entity engine::rtype::CheatButton::click(ecs::Entity entity)
{
    ecs::SpriteAnimation &animation = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(entity);
    engine::rtype::SettingsManager &settings = engine::rtype::SettingsManager::getInstance();
    if (settings.cheat == 0) {
        settings.cheat = 1;
        animation.toSet = true;
        animation.setTo = {1, animation.current.second};
    }
    else {
        settings.cheat = 0;
        animation.toSet = true;
        animation.setTo = {0, animation.current.second};
    }

    return (entity);
}


void engine::rtype::CheatButton::hover(ecs::Entity entity)
{
    ecs::SpriteAnimation &animation = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(entity);

    animation.toSet = true;
    animation.setTo = {animation.current.first, 1};
}

void engine::rtype::CheatButton::resetHover(ecs::Entity entity)
{
    ecs::SpriteAnimation &animation = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(entity);

    animation.toSet = true;
    animation.setTo = {animation.current.first, 0};
}