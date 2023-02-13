#include <Settings.hpp>
#include <src/PowerUp.hpp>

PowerUp::PowerUp(float _x, float _y) noexcept 
    : x{_x}, y{_y}, power{Settings::textures["power"]}
{

}

void PowerUp::reset(float _x, float _y) noexcept
{
    x = _x;
    y = _y;
}

sf::FloatRect PowerUp::get_collision_rect() const noexcept
{
    return sf::FloatRect{x, y, Settings::POWER_WIDTH, Settings::POWER_HEIGHT};
}

bool PowerUp::is_out_of_game() const noexcept
{
    return x < Settings::POWER_WIDTH;
}

void PowerUp::update(float dt) noexcept
{
    x += -Settings::MAIN_SCROLL_SPEED * dt;    
    
    power.setPosition(x, y);
}

void PowerUp::render(sf::RenderTarget& target) const noexcept
{
    target.draw(power);
}
