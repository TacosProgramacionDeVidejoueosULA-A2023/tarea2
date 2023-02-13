#pragma once

#include <src/modes/BaseGameMode.hpp>

class HardMode : public BaseGameMode
{
public:
    HardMode(std::shared_ptr<Bird> _bird = nullptr, std::shared_ptr<World> _world = nullptr, StateMachine* _sm = nullptr);

    void init() noexcept override;

    void handle_inputs(const sf::Event &event) noexcept override;

    void update(float dt) noexcept override;

    void render(sf::RenderTarget &target) const noexcept override;
};
