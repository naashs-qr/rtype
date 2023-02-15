/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** IWindow
*/

#ifndef IWINDOW_HPP_
    #define IWINDOW_HPP_

namespace lib {
    class IWindow {
        public:
            virtual void create() = 0;
        private:
    };
}

#endif /* !IWINDOW_HPP_ */
