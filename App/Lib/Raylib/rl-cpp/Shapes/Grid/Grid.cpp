/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo [WSL : Ubuntu]
** File description:
** Grid
*/

#include "Lib/Raylib/rl-cpp/Shapes/Grid/Grid.hpp"

void rl::Grid::draw() const                                                  // Draw Grid
{
    ::DrawGrid(slices, spacing);
}
