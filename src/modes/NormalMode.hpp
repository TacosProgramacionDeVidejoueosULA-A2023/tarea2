#pragma once

#include <src/modes/BaseGameMode.hpp>

class NormalMode : public BaseGameMode
{
public:
    NormalMode(std::shared_ptr<Bird> bird = nullptr, std::shared_ptr<World> world = nullptr, StateMachine* sm = nullptr);

    void init() noexcept override;

    void handle_inputs(const sf::Event &event) noexcept override;

    void update(float dt) noexcept override;

    void render(sf::RenderTarget &target) const noexcept override;
};