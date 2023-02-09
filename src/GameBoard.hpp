/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Jorge Luis Rodríguez González
    egroj97@gmail.com

    This file contains the declaration of the class Game.
*/

#include <src/modes/BaseGameMode.hpp>
#include <src/World.hpp>
#include <shared_mutex>

#pragma once

class GameBoard
{
public:
    GameBoard(std::shared_ptr<World> _world) noexcept;

    GameBoard(const GameBoard &GameBoard) = delete;
    
    GameBoard &operator=(GameBoard) = delete;

    void update(float dt) noexcept;

private:
    std::shared_ptr<BaseGameMode> current_game_mode{std::make_shared<BaseGameMode>()};
    std::shared_ptr<World> world;
};
