/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** GameManager
*/

#include "GameEngine/Managers/GameManager.hpp"
#include "GameEngine/Managers/SoundManager.hpp"
#include "GameEngine/Map/Map.hpp"
#include "GameEngine/Square.hpp"
#include "GameEngine/Spawner.hpp"
#include "GameEngine/Player.hpp"
#include "GameEngine/RType/Particles/Propulsion.hpp"
#include "GameEngine/RType/Particles/Shield.hpp"
#include "GameEngine/RType/Shader/WaveShader.hpp"
#include "GameEngine/RType/Shader/ColorShader.hpp"
#include "GameEngine/RType/Shader/LightShader.hpp"
#include "GameEngine/RType/Shader/RainShader.hpp"
#include "GameEngine/RType/Shader/GalaxyShader.hpp"

#include "GameEngine/RType/Shoot/SmallShip.hpp"
#include "GameEngine/Managers/PlayerManager.hpp"
#include "GameEngine/Managers/LevelManager.hpp"

#include "GameEngine/Managers/FontManager.hpp"

#include "GameEngine/Managers/SettingsManager.hpp"
#include "GameEngine/RType/LeaderBoard.hpp"

#include "GameEngine/GameEntities.hpp"
#include "GameEngine/LinkerEntities.hpp"
#include "GameEngine/UI.hpp"



#include "GameEngine/RType/Enemy/SpaceShipEnemy.hpp"
#include "GameEngine/RType/Enemy/BrainAlienEnemy.hpp"
#include "GameEngine/RType/Enemy/CyborgBobEnemy.hpp"
#include "GameEngine/RType/Enemy/CyborgDamsEnemy.hpp"
#include "GameEngine/RType/Enemy/CyborgMegakongEnemy.hpp"
#include "GameEngine/RType/Boss/Beric.hpp"
#include "GameEngine/RType/Boss/ContreUno.hpp"
#include "GameEngine/RType/Title.hpp"
#include "GameEngine/RType/Boss/Feur.hpp"

#include "Lib/Raylib/rl-cpp/Texts/Texts.hpp"
#include "Lib/Raylib/rl-cpp/Colors/Colors.hpp"
#include "Lib/Raylib/rl-cpp/Shaders/Shaders.hpp"



// INIT ------------------------------------------------------------------------

// std::array<bool, 4> _players = {false, true, true, true};
// rl::Vector2 const &screenSize = {
//     float(rl::Window::getInstance().getWidth()),
//     float(rl::Window::getInstance().getHeight())
// };

void engine::GameManager::initMenu()
{
    engine::rtype::SpaceParallax parallax;
    engine::rtype::SettingsManager::getInstance();
    engine::rtype::Title title;
    ecs::Entity playButton = engine::rtype::PlayButton::construct();
    ecs::Entity selector = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
        selector,
        ecs::Selector {
            .selected = playButton
        }
    );
    ecs::Coordinator::getInstance().addComponent(
        selector,
        ecs::Control {
            .eventID = 0,
            .secondary = false
        }
    );
    // std::cout << "Menu end" << std::endl;
}

void engine::GameManager::initWinLoose()
{
    std::cout << "init Win loose" << std::endl;
    engine::rtype::SpaceParallax parallax;

    engine::rtype::Title title;
    ecs::Entity Text1 = ecs::Coordinator::getInstance().createEntity();
    ::ecs::Coordinator::getInstance().addComponent(
        Text1,
        ecs::RLText(
            ::rl::Text("Press Space to return to menu", 
                ::rl::Font(engine::FontManager::getInstance().getData(engine::FontType::FONT_BOLD)), 
                35, 
                ::rl::Color(255, 255, 255, 255), 
                ::rl::Vector2(650, 900)),
            0
        )
    );
    ::ecs::Coordinator::getInstance().addComponent(
        Text1, 
        ecs::Transform {
            .position = {0, 0},
            .rotation = 0.0,
            .scale = 1.0
        }
    );

}

void engine::GameManager::initGame()
{
    engine::LevelManager &lm = engine::LevelManager::getInstance();
    engine::GameManager &gm = engine::GameManager::getInstance();
    lm.instanciate(gm._lvl);

    engine::GameEntities &entities = engine::GameEntities::getInstance();
    ecs::Coordinator &coord = ecs::Coordinator::getInstance();
    engine::Shader *textureShader = static_cast<engine::Shader *> (lm.getTextureShaderPtr().get());
    engine::Shader *ambiantShader = static_cast<engine::Shader *> (lm.getAmbiantShaderPtr().get());

    engine::rtype::PlayerManager &players = engine::rtype::PlayerManager::getInstance();
    players.instanciate(gm._lvl);
    // engine::rtype::RaygunBonus bonus(::game::Vector2(1000, 200));
    // engine::rtype::BigShipBonus bonus1(::game::Vector2(1000, 400));
    // engine::rtype::SmallShipBonus bonus2(::game::Vector2(1000, 600));
    // engine::rtype::ShieldBonus bonus3(::game::Vector2(1000, 800));

    // engine::rtype::GalaxyShader galaxyShader;
    // galaxyShader.addShaderedEntity(bonus3.entity);

    // engine::rtype::BrainAlienEnemy nmi;
    // engine::rtype::SpaceShipEnemy nmi1;
    // engine::rtype::CyborgBobEnemy nmi2;
    // engine::rtype::CyborgDamsEnemy nmi3;
    // engine::rtype::CyborgMegakongEnemy nmi15;
    // engine::rtype::ContreUno nmi4;
    // engine::rtype::Beric nmi5;
    // engine::rtype::Feur nmi6;

    // ecs::UI ui;
    engine::UI ui;
    auto player = players.getPlayers();
    for (auto &p : player) {
        textureShader->addShaderedEntity(p->getEntity());
        ambiantShader->addShaderedEntity(p->getEntity());
    }


    // textureShader->addShaderedEntity(players.getPlayer(0));
    // textureShader->addShaderedEntity(players.getPlayer(1));
    // textureShader->addShaderedEntity(players.getPlayer(2));
    // textureShader->addShaderedEntity(players.getPlayer(3));


    // ambiantShader->addShaderedEntity(players.getPlayer(0));
    // ambiantShader->addShaderedEntity(players.getPlayer(1));
    // ambiantShader->addShaderedEntity(players.getPlayer(2));
    // ambiantShader->addShaderedEntity(players.getPlayer(3));


    // ecs::Entity  entity = coord.createEntity();
    // engine::UI ui;

//    ecs::Entity ent = coord.createEntity();
//    coord.addComponent(
//        ent,
//        ecs::SoundEffect {
//            .loop = false,
//            .repeat = 3,
//            .isPlaying = false,
//            .sound = engine::SoundManager::getInstance().getData(engine::SoundType::SO_BOSS1)
//        }
//    );
}

void engine::GameManager::loopGame(engine::PollEvent &pollEvent)
{

    ecs::Coordinator &coord = ecs::Coordinator::getInstance();
    
    ::rl::Window &win = ::rl::Window::getInstance();
    engine::rtype::PlayerManager &players = engine::rtype::PlayerManager::getInstance();
    engine::LevelManager::getInstance().runMap(pollEvent.dt);
    engine::Boss *boss = static_cast<engine::Boss *> (engine::LevelManager::getInstance().getBossPtr().get());



    win.clearBackground();
    pollEvent.playerEvents[0] = engine::RLEventHandler::getEvent();


    if ((pollEvent.playerEvents[0].pressed & engine::QUIT) == engine::QUIT) {
        pollEvent.quit = true;
    }

    coord.getSystem(ecs::SPAWN_SYSTEM)->update(pollEvent);
    coord.getSystem(ecs::CONTROL_MOVE_SYSTEM)->update(pollEvent);  
    coord.getSystem(ecs::AI_SYSTEM)->update(pollEvent);  
    coord.getSystem(ecs::SHOOT_SYSTEM)->update(pollEvent);  
    coord.getSystem(ecs::BULLET_SYSTEM)->update(pollEvent); 
    coord.getSystem(ecs::SCROLL_SYSTEM)->update(pollEvent); 
    coord.getSystem(ecs::TEMPORARY_SYSTEM)->update(pollEvent);   
    coord.getSystem(ecs::MOVEMENT_SYSTEM)->update(pollEvent);  
    coord.getSystem(ecs::PARALLAX_SYSTEM)->update(pollEvent);  
    coord.getSystem(ecs::BOUND_SYSTEM)->update(pollEvent);  
    coord.getSystem(ecs::LIFE_SYSTEM)->update(pollEvent);  
    coord.getSystem(ecs::SOUND_SYSTEM)->update(pollEvent);
    
    engine::GameManager::getInstance().manageLevel(boss);
    

    if (players.checkLoose()) {
        pollEvent.quit = true;
    }

    win.beginDrawing();
        win.beginMode2D();

            coord.getSystem(ecs::PARALLAX_DRAW_SYSTEM)->update(pollEvent);
            coord.getSystem(ecs::COLLISION_SYSTEM)->update(pollEvent);
            coord.getSystem(ecs::ANIMATE_SYSTEM)->update(pollEvent);
            coord.getSystem(ecs::PARTICLES_SYSTEM)->update(pollEvent);
            coord.getSystem(ecs::DRAW_SYSTEM)->update(pollEvent);
            coord.getSystem(ecs::DRAW_TEXT_SYSTEM)->update(pollEvent);
            coord.getSystem(ecs::UI_RENDER_SYSTEM)->update(pollEvent);
        win.endMode2D();
        coord.getSystem(ecs::SHADER_SYSTEM)->update(pollEvent);
        win.beginMode2D();
        win.endMode2D();
    win.endDrawing();
}

// void GameManager::initPause();

// LOOPS -----------------------------------------------------------------------

void engine::GameManager::loopMenu(engine::PollEvent &pollEvent)
{
    ecs::Coordinator &coord = ecs::Coordinator::getInstance();
    ::rl::Window &win = ::rl::Window::getInstance();
    win.clearBackground();
    ecs::Entity ent = ecs::Coordinator::getInstance().createEntity();
    SO_Menu::attach(ent, 1);

    pollEvent.playerEvents[0] = engine::RLEventHandler::getEvent();
    if (((pollEvent.playerEvents[0].pressed & engine::QUIT) == engine::QUIT) || engine::GameManager::getInstance()._quit == true)  {
        pollEvent.quit = true;
    }
    // ecs::Coordinator::getInstance().getSystem(ecs::CONTROL_MOVE_SYSTEM)->update(pollEvent);
    // ecs::Coordinator::getInstance().getSystem(ecs::MOVEMENT_SYSTEM)->update(pollEvent);
    coord.getSystem(ecs::BUTTON_SYSTEM)->update(pollEvent);
    coord.getSystem(ecs::ANIMATE_SYSTEM)->update(pollEvent);

    // win.clearBackground();
    // pollEvent.playerEvents[0] = engine::RLEventHandler::getEvent();
        // std::cout << "quit" << std::endl;
    coord.getSystem(ecs::SELECTOR_SYSTEM)->update(pollEvent);
    coord.getSystem(ecs::SCROLL_SYSTEM)->update(pollEvent);
    win.beginDrawing();
        win.beginMode2D();
            coord.getSystem(ecs::PARALLAX_DRAW_SYSTEM)->update(pollEvent);
            coord.getSystem(ecs::DRAW_SYSTEM)->update(pollEvent);
            coord.getSystem(ecs::DRAW_TEXT_SYSTEM)->update(pollEvent);
        win.endMode2D();
    win.endDrawing();


}


void engine::GameManager::loopWinLoose(engine::PollEvent &pollEvent)
{
    ecs::Coordinator &coord = ecs::Coordinator::getInstance();
    ::rl::Window &win = ::rl::Window::getInstance();
    win.clearBackground();
    // std::cout << "loopWinLoose" << std::endl;

    pollEvent.playerEvents[0] = engine::RLEventHandler::getEvent();
    if (((pollEvent.playerEvents[0].pressed & engine::QUIT) == engine::QUIT) || engine::GameManager::getInstance()._quit == true)  {
        pollEvent.quit = true;
    }
    if (((pollEvent.playerEvents[0].pressed & engine::SHOOT) == engine::SHOOT))  {
        std::cout << "Return menu" << std::endl;
        pollEvent.quit = true;
    }


    coord.getSystem(ecs::ANIMATE_SYSTEM)->update(pollEvent);


    coord.getSystem(ecs::SCROLL_SYSTEM)->update(pollEvent);
    win.beginDrawing();
        win.beginMode2D();
            coord.getSystem(ecs::PARALLAX_DRAW_SYSTEM)->update(pollEvent);
            coord.getSystem(ecs::DRAW_SYSTEM)->update(pollEvent);
            coord.getSystem(ecs::DRAW_TEXT_SYSTEM)->update(pollEvent);
        win.endMode2D();
    win.endDrawing();


}



void engine::GameManager::manageLevel(engine::Boss *boss)
{
    
    engine::GameManager &gm = engine::GameManager::getInstance();
    if (gm._delayTransition == -1) {
        if (boss->update(boss) == false) {
            engine::rtype::Title title;
            engine::rtype::LeaderBoard lb;
            gm._delayTransition = 1000;
        }
    }
    else if (gm._delayTransition != -1)
    {
        if (gm._delayTransition == 0)
        {
            gm._lvl++;
            gm._delayTransition = -1;
            engine::LevelManager &lm = engine::LevelManager::getInstance();
            engine::rtype::PlayerManager &players = engine::rtype::PlayerManager::getInstance();
            engine::Shader *textureShader = static_cast<engine::Shader *> (lm.getTextureShaderPtr().get());
            engine::Shader *ambiantShader = static_cast<engine::Shader *> (lm.getAmbiantShaderPtr().get());
            auto player = players.getPlayers();
            for (auto &p : player) {
                textureShader->removeShaderedEntity(p->getEntity());
                ambiantShader->removeShaderedEntity(p->getEntity());
            }
            
            // gm.clearWindow();
            gm.pushWindow(WindowState::GAME);
        }
        gm._delayTransition--;

    }
}