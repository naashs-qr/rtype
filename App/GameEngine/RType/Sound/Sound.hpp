/*
** EPITECH PROJECT, 2022
** RType
** File description:
** sound.hpp
*/

#pragma once

#include "GameEngine/Managers/SoundManager.hpp"
#include "GameEngine/Entity.hpp"
#include "ECS/Entity.hpp"

namespace engine {
    template<engine::SoundType ST>
    class Sound : public engine::Entity{
        public:
            Sound() : Entity(){
                ecs::SoundEffect Snd;
                Snd = ecs::SoundEffect {
                        .loop = false,
                        .repeat = 1,
                        .isPlaying = false,
                        .sound = engine::SoundManager::getInstance().getData(ST),
                };
                Snd.sound.setVolume(0.5);
                Snd.sound.updateVolume();
                ecs::Coordinator::getInstance().template addComponent(
                        this->entity,
                        Snd
                        );

            }
            static void attach(ecs::Entity ent, float volume) {
                ecs::SoundEffect Snd = ecs::SoundEffect {
                        .loop = true,
                        .repeat = 1,
                        .isPlaying = false,
                        .sound = engine::SoundManager::getInstance().getData(ST)
                };
                   ecs::Coordinator::getInstance().template addComponent(
                           ent,
                           Snd
                   );
                   Snd.sound.setVolume(volume);
                   Snd.sound.updateVolume();
            }
    };
    typedef Sound<::engine::SoundType::SO_BASIC_SHOT> SO_BasicShot;
    typedef Sound<::engine::SoundType::SO_RAY_GUN> SO_RayGun;
    typedef Sound<::engine::SoundType::SO_DEATH_SE> SO_DeathSE;
    typedef Sound<::engine::SoundType::SO_LOSE_SCREEN> SO_LoseScreen;
    typedef Sound<::engine::SoundType::SO_PICK_UP_SE> SO_PickUpSE;
    typedef Sound<::engine::SoundType::SO_SHIELD_SE> SO_ShieldSE;
    typedef Sound<::engine::SoundType::SO_WIN_SCREEN> SO_WinScreen;
    typedef Sound<::engine::SoundType::SO_BG_MENU> SO_Menu;
    typedef Sound<::engine::SoundType::SO_BG_MUS> SO_InGame;
    typedef Sound<::engine::SoundType::SO_BOSS1> SO_Boss;
}