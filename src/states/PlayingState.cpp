/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class PlayingBaseState.
*/

#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/PlayingState.hpp>

PlayingState::PlayingState(StateMachine *sm) noexcept
    : BaseState{sm}
{
}

void PlayingState::enter(std::shared_ptr<World> _world, std::shared_ptr<Bird> _bird, std::shared_ptr<BaseGameMode> _mode) noexcept
{
    current_mode = _mode;
    current_mode->init();
}

void PlayingState::handle_inputs(const sf::Event &event) noexcept
{
    current_mode->handle_inputs(event);
}

void PlayingState::update(float dt) noexcept
{
    current_mode->update(dt);
}

void PlayingState::render(sf::RenderTarget &target) const noexcept
{
    current_mode->render(target);
}