#pragma once

#include <SFML/Graphics.hpp>
#include <shared_mutex>

class StateMachine;
class World;
class Bird;

class BaseGameMode
{
public:
    BaseGameMode(std::shared_ptr<Bird> _bird = nullptr, std::shared_ptr<World> _world = nullptr, StateMachine* _sm = nullptr)
        : bird{_bird}, world{_world}, state_machine{_sm} {}

    virtual ~BaseGameMode() {}

    virtual void init() noexcept {}

    virtual void handle_inputs(const sf::Event &event) noexcept {}

    virtual void update(float dt) noexcept {}

    virtual void render(sf::RenderTarget &target) const noexcept {}

    void set_bird(std::shared_ptr<Bird> _bird) noexcept {
        bird = _bird;
    }

    void set_world(std::shared_ptr<World> _world) noexcept {
        world = _world;
    }

protected:
    std::shared_ptr<Bird> bird;
    std::shared_ptr<World> world;
    StateMachine* state_machine;
    int score{0};
};
