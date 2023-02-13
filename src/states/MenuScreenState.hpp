#pragma once

#include <src/World.hpp>
#include <src/states/BaseState.hpp>
#include <array>

class MenuScreenState: public BaseState
{
public:
    MenuScreenState(StateMachine* sm) noexcept;

    void handle_inputs(const sf::Event& event) noexcept override;

    void update(float dt) noexcept override;

    void render(sf::RenderTarget& target) const noexcept override;

private:
    World world;
    int selected;
    std::array<std::string, 2> options;
};
