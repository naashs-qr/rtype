/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** SettingsManager
*/

#ifndef SETTINGSMANAGER_HPP_
#define SETTINGSMANAGER_HPP_

namespace engine {
namespace rtype {


class SettingsManager {
    private:
        SettingsManager() {
            this->sound = 1;
            this->cheat = 0;
            
        }
        ~SettingsManager() = default;

    public:
        static SettingsManager &getInstance()
        {
            static SettingsManager instance;
            return (instance);
        }

        int sound;
        int cheat;

        // std::vector<
};
}
}

#endif /* !PLAYERMANAGER_HPP_ */
