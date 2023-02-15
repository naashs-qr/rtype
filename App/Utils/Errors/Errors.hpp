/*
** EPITECH PROJECT, 2022
** Plazza (Workspace)
** File description:
** Errors
*/

#ifndef ERRORS_HPP_
    #define ERRORS_HPP_

    #include <iostream>
    #include <string>

class Errors : public std::exception {
    public:
        explicit Errors(
            std::string const &message,
            std::string const &component = "IndieStudio"
        )
            : _message("\e[31m" + message + "\e[39m")
        {
            (void)component;
        }

        char const *what() const throw() {
            return this->_message.c_str();
        }

        static void printError(std::string const &message) {
            std::cerr << "\e[31m" + message + "\e[39m" << std::endl;
        }

    private:
        std::string _message;
};

class ECSError : public Errors
{
    public:
        explicit ECSError(
            std::string const &message,
            std::string const &component = "ECS"
        )
            : Errors(message, component)
        {}
};

class GraphicsError : public Errors
{
    public:
        explicit GraphicsError(
            std::string const &message,
            std::string const &component = "Graphics"
        )
            : Errors(message, component)
        {}
};



#endif /* !ERRORS_HPP_ */
