/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** EntityFactory
*/

#ifndef ENTITYFACTORY_HPP_
    #define ENTITYFACTORY_HPP_

    #include "GameEngine/Entity.hpp"
    #include "GameEngine/Player.hpp"
    #include "GameEngine/PollEvent.hpp"
    #include "GameEngine/RType/Shader/LightShader.hpp"
    #include "GameEngine/RType/Shader/WaveShader.hpp"
    #include "GameEngine/RType/Shader/ColorShader.hpp"
    #include "GameEngine/RLEventHandler.hpp"
    #include "GameEngine/SpaceParallax.hpp"
    #include "GameEngine/RType/Button/PlayButton.hpp"

    #include "GameEngine/RType/Bonus/BigShipBonus.hpp"
    #include "GameEngine/RType/Bonus/RaygunBonus.hpp"
    #include "GameEngine/RType/Bonus/ShieldBonus.hpp"
    #include "GameEngine/RType/Bonus/SmallShipBonus.hpp"

    #include "GameEngine/RType/Enemy/SpaceShipEnemy.hpp"
    #include "GameEngine/RType/Enemy/BrainAlienEnemy.hpp"
    #include "GameEngine/RType/Enemy/CyborgBobEnemy.hpp"
    #include "GameEngine/RType/Enemy/CyborgDamsEnemy.hpp"
    #include "GameEngine/RType/Enemy/CyborgMegakongEnemy.hpp"

    #include "GameEngine/RType/Boss/Beric.hpp"
    #include "GameEngine/RType/Boss/ContreUno.hpp"
    #include "GameEngine/RType/Boss/Feur.hpp"

namespace engine {
enum EntityType {
    PLAYER1 = 0,
    PLAYER2 = 1,
    PLAYER3 = 2,
    PLAYER4 = 3,
    PLAYER1_ATTACH = 4,
    PLAYER2_ATTACH = 5,
    PLAYER3_ATTACH = 6,
    PLAYER4_ATTACH = 7,
    ENEMY = 8,
    BULLET = 9,
    WALL = 10,
    POWERUP = 11,
    PLAY_BUTTON = 12,
    SPACE_PARALLAX = 13,
    ENEMY1 = 14,
    SPOT_SHAD = 15,
    COLOR_SHAD = 16,
    WAVE_SHAD = 17,
    BERIC = 18,
    CONTREUNO = 19,
    FEUR = 20,
    ALIEN = 21,
    BOB = 22,
    MEGAKONG = 23,
    DAMS = 24,
    SMALL_SHIP_BON = 25,
    BIG_SHIP_BON = 26,
    SHIELD_BON = 27,
    RAILGUN_BON = 28

};


class EntityFactory {
    public:
        EntityFactory() = delete;
        ~EntityFactory() = delete;

        static std::shared_ptr<engine::IEntity> createEngineEntity(EntityType type);

        static std::shared_ptr<engine::IEntity> createShipPlayer1()
        {
            engine::rtype::ShipPlayer<1>  entity;
            return (std::make_shared<engine::rtype::ShipPlayer<1>>(entity));
        };
        static std::shared_ptr<engine::IEntity> createShipPlayer2()
        {
            engine::rtype::ShipPlayer<2> entity;
            return (std::make_shared<engine::rtype::ShipPlayer<2>>(entity));
        };
        static std::shared_ptr<engine::IEntity> createShipPlayer3()
        {
            engine::rtype::ShipPlayer<3> entity;
            return (std::make_shared<engine::rtype::ShipPlayer<3>>(entity));
        };
        static std::shared_ptr<engine::IEntity> createShipPlayer4()
        {
            engine::rtype::ShipPlayer<4> entity;
            return (std::make_shared<engine::rtype::ShipPlayer<4>>(entity));
        };
        static std::shared_ptr<engine::IEntity> createPlayButton()
        {
            engine::rtype::PlayButton entity;
            return (std::make_shared<engine::rtype::PlayButton>(entity));
        };
        static std::shared_ptr<engine::IEntity> createSpaceParallax()
        {
            engine::rtype::SpaceParallax entity;
            return (std::make_shared<engine::rtype::SpaceParallax>(entity));
        };
        static std::shared_ptr<engine::IEntity> createSpaceEnemy()
        {
            engine::rtype::SpaceShipEnemy entity;
            return (std::make_shared<engine::rtype::SpaceShipEnemy>(entity));
        };
        static std::shared_ptr<engine::IEntity> createLightShader()
        {
            engine::rtype::LightShader entity;
            return (std::make_shared<engine::rtype::LightShader>(entity));
        };
        static std::shared_ptr<engine::IEntity> createWaveShader()
        {
            engine::rtype::WaveShader entity;
            return (std::make_shared<engine::rtype::WaveShader>(entity));
        };
        static std::shared_ptr<engine::IEntity> createColorShader()
        {
            engine::rtype::ColorShader entity;
            return (std::make_shared<engine::rtype::ColorShader>(entity));
        };

        static std::shared_ptr<engine::IEntity> createBeric()
        {
            engine::rtype::Beric entity;
            return (std::make_shared<engine::rtype::Beric>(entity));
        };

        static std::shared_ptr<engine::IEntity> createContreUno()
        {
            engine::rtype::ContreUno entity;
            return (std::make_shared<engine::rtype::ContreUno>(entity));
        };

        static std::shared_ptr<engine::IEntity> createFeur()
        {
            engine::rtype::Feur entity;
            return (std::make_shared<engine::rtype::Feur>(entity));
        };

        static std::shared_ptr<engine::IEntity> createBob()
        {
            engine::rtype::CyborgBobEnemy entity;
            return (std::make_shared<engine::rtype::CyborgBobEnemy>(entity));
        };

        static std::shared_ptr<engine::IEntity> createDams()
        {
            engine::rtype::CyborgDamsEnemy entity;
            return (std::make_shared<engine::rtype::CyborgDamsEnemy>(entity));
        };

        static std::shared_ptr<engine::IEntity> createMegakong()
        {
            engine::rtype::CyborgMegakongEnemy entity;
            return (std::make_shared<engine::rtype::CyborgMegakongEnemy>(entity));
        };

        static std::shared_ptr<engine::IEntity> createAlien()
        {
            engine::rtype::BrainAlienEnemy entity;
            return (std::make_shared<engine::rtype::BrainAlienEnemy>(entity));
        };

        static std::shared_ptr<engine::IEntity> createBigShipBonus()
        {
            engine::rtype::BigShipBonus entity;
            return (std::make_shared<engine::rtype::BigShipBonus>(entity));
        };
        
        static std::shared_ptr<engine::IEntity> createSmallShipBonus()
        {
            engine::rtype::SmallShipBonus entity;
            return (std::make_shared<engine::rtype::SmallShipBonus>(entity));
        };
        
        static std::shared_ptr<engine::IEntity> createShieldBonus()
        {
            engine::rtype::ShieldBonus entity;
            return (std::make_shared<engine::rtype::ShieldBonus>(entity));
        };
        
        static std::shared_ptr<engine::IEntity> createRaygunBonus()
        {
            engine::rtype::RaygunBonus entity;
            return (std::make_shared<engine::rtype::RaygunBonus>(entity));
        };
        
        static ecs::Entity createEntity(EntityType type);
};
} // namespace engine

#endif /* !ENTITYFACTORY_HPP_ */
