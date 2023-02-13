/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Jorge Rodríguez
    egroj97@gmail.com

    This file contains the definition of the class PauseState.
*/

#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/PauseState.hpp>

PauseState::PauseState(StateMachine* sm) noexcept
    : BaseState{sm}
{

}

void PauseState::enter(std::shared_ptr<World> _world, std::shared_ptr<Bird> _bird, std::shared_ptr<BaseGameMode> _mode) noexcept
{
    world = _world;
    bird = _bird;
    mode = _mode;
}

void PauseState::handle_inputs(const sf::Event& event) noexcept
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
    {
        state_machine->change_state("playing", world, bird, mode);
    }
}

void PauseState::update(float dt) noexcept {

}

void PauseState::render(sf::RenderTarget& target) const noexcept
{
    world->render(target);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 2, "Paused", Settings::FLAPPY_TEXT_SIZE, "font", sf::Color::White, true);
}