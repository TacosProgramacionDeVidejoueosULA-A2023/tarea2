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
    world = _world;
    current_mode->init();

    if (_bird == nullptr)
    {
        bird = std::make_shared<Bird>(
            Settings::VIRTUAL_WIDTH / 2 - Settings::BIRD_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 2 - Settings::BIRD_HEIGHT / 2,
            Settings::BIRD_WIDTH, Settings::BIRD_HEIGHT
        );
        world->reset(true);
    }
    else
    {
        bird = _bird;
        
        if (bird->is_ghost()) {
            Settings::power_music.play();
        }
        else {
            Settings::music.play();
        }
    }
}

void PlayingState::handle_inputs(const sf::Event &event) noexcept
{
    current_mode->handle_inputs(event);
}

void PlayingState::update(float dt) noexcept
{
    current_mode->update(dt);

    if (bird->is_ghost())
    {
        powerup_limit_timer += dt;
        
        if (powerup_limit_timer >= Settings::POWERUP_TIME_PERIOD)
        {    
            powerup_limit_timer = 0.f;
            bird->turn_ghost(false);
            world->reset(true);
            Settings::power_music.stop();
            Settings::music.play();
        }
    }

    if (world->collides_with_power(bird->get_collision_rect())) 
    {
        Settings::music.pause();
        Settings::power_music.play();
        Settings::power_music.setLoop(true);
        bird->turn_ghost(true);
    }
}

void PlayingState::render(sf::RenderTarget &target) const noexcept
{
    current_mode->render(target);
}