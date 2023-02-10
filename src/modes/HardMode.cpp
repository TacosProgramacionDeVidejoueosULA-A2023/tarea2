#include <src/modes/HardMode.hpp>
#include <src/Bird.hpp>
#include <src/World.hpp>
#include <Settings.hpp>

HardMode::HardMode(std::shared_ptr<Bird> _bird, std::shared_ptr<World> _world, StateMachine* _sm)
    : BaseGameMode{_bird, _world, _sm}
{
    world->reset(true);

    if (_bird == nullptr)
    {
        bird = std::make_shared<Bird>(
            Settings::VIRTUAL_WIDTH / 2 - Settings::BIRD_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 2 - Settings::BIRD_HEIGHT / 2,
            Settings::BIRD_WIDTH, Settings::BIRD_HEIGHT);
    }
    else
    {
        bird = _bird;
    }
}