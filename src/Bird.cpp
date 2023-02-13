/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class Bird.
*/

#include <Settings.hpp>
#include <src/Bird.hpp>

Bird::Bird(float _x, float _y, float w, float h) noexcept
    : x{_x}, y{_y}, width{w}, height{h}, vy{0.f}, vx{0.f}, sprite{Settings::textures["bird"]}
{
    sprite.setPosition(x, y);
}

sf::FloatRect Bird::get_collision_rect() const noexcept
{
    return sf::FloatRect{x, y, width, height};
}

void Bird::jump() noexcept
{
    if (!jumping)
    {
        jumping = true;
    }
}

void Bird::turn_ghost(bool _ghost) noexcept
{
    ghost = _ghost;
    if(ghost){
        sprite.setColor(sf::Color(255, 255, 255, 128));
    } else {
        sprite.setColor(sf::Color(255, 255, 255));
    }
}

bool Bird::is_ghost() const noexcept
{
    return ghost;
}

void Bird::move_left() noexcept
{
    vx = -Settings::BIRD_SPEED;
}

void Bird::move_right() noexcept
{
    vx = Settings::BIRD_SPEED;
}

void Bird::update(float dt) noexcept
{
    vy += Settings::GRAVITY * dt;

    if (jumping)
    {
        Settings::sounds["jump"].play();
        vy = -Settings::JUMP_TAKEOFF_SPEED;
        jumping = false;
    }

    y += vy * dt;
    x += vx * dt;
    vx = 0.f;

    sprite.setPosition(x, y);
    if(ghost){
        sprite.setColor(sf::Color(255, 255, 255, 128));
    } else {
        sprite.setColor(sf::Color(255, 255, 255));
    }
}

void Bird::render(sf::RenderTarget& target) const noexcept
{
    target.draw(sprite);
}