#pragma once

class BaseGameMode
{
public:
    BaseGameMode() {}

    virtual ~BaseGameMode() {}

    virtual void update(float dt) noexcept {}

    virtual void handle_inputs(const sf::Event& event) noexcept {}
};
