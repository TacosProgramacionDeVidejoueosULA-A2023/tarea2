/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the declaration of the class World.
*/

#pragma once

#include <list>
#include <memory>
#include <random>

#include <SFML/Graphics.hpp>

#include <src/Factory.hpp>
#include <src/LogPair.hpp>
#include <src/PowerUp.hpp>

class World
{
public:
    World(bool _generate_logs = false) noexcept;

    World(const World& world) = delete;

    World& operator = (World) = delete;

    void reset(bool _generate_logs) noexcept;

    bool collides(const sf::FloatRect& rect) const noexcept;

    bool update_scored(const sf::FloatRect& rect) noexcept;

    void update(float dt) noexcept;

    void update_hard_mode(float dt) noexcept;

    void render(sf::RenderTarget& target) const noexcept;

     bool collides_with_power(const sf::FloatRect& rect) noexcept;
     
private:
    bool generate_logs;

    sf::Sprite background;
    sf::Sprite ground;

    float background_x{0.f};
    float ground_x{0.f};

    Factory<PowerUp> powers_factory;
    Factory<LogPair> log_factory;

    bool power_up{false};
    std::shared_ptr<PowerUp> power;
    std::list<std::shared_ptr<LogPair>> logs;

    std::mt19937 rng;

    float logs_spawn_timer{0.f};
    float logs_spawn_time;
    float power_spawn_timer{0.f};
    float last_log_y{0.f};
};
