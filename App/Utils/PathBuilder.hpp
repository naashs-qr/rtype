/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** PathBuilder
*/

#ifndef PATHBUILDER_HPP_
#define PATHBUILDER_HPP_

    #include <iostream>
    #include <stdlib.h>
    #include <string>
    #include <vector>

namespace game {

    class PathBuilder {

        public:
            static std::string getPath(std::vector<std::string> path) {
                std::string sep;
                std::string finalPath = "";

                #ifdef _WIN32
                    sep = "\\";
                #else
                    sep = "/";
                #endif

                for (size_t i = 0; i < path.size(); i++) {
                    finalPath += path[i];
                    if (i != path.size() - 1)
                        finalPath += sep;
                }
                return finalPath;
            }
    };
};


#endif /* !PATHBUILDER_HPP_ */
