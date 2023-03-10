#include <src/modes/HardMode.hpp>
#include <src/states/CountDownState.hpp>
#include <src/states/PlayingState.hpp>
#include <src/states/PauseState.hpp>
#include <Settings.hpp>
#include <src/Bird.hpp>
#include <src/World.hpp>
#include <src/states/StateMachine.hpp>
#include <src/text_utilities.hpp>

HardMode::HardMode(std::shared_ptr<Bird> _bird, std::shared_ptr<World> _world, StateMachine* _sm)
    : BaseGameMode{_bird, _world, _sm}
{
}

void HardMode::init() noexcept
{
    world->reset(true);

    if (bird == nullptr)
    {
        bird = std::make_shared<Bird>(
            Settings::VIRTUAL_WIDTH / 2 - Settings::BIRD_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 2 - Settings::BIRD_HEIGHT / 2,
            Settings::BIRD_WIDTH, Settings::BIRD_HEIGHT);
    }
}

void HardMode::handle_inputs(const sf::Event &event) noexcept
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        bird->jump();
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
        bird->move_left();
    }
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
        bird->move_right();
    }
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
    {
        state_machine->change_state("pause", world, std::shared_ptr<Bird>(bird), std::make_shared<HardMode>(bird, world, state_machine));
    }
}

void HardMode::update(float dt) noexcept
{
    bird->update(dt);
    world->update_hard_mode(dt);

    if (!bird->is_ghost() && world->collides(bird->get_collision_rect()))
    {
        Settings::sounds["explosion"].play();
        Settings::sounds["hurt"].play();
        state_machine->change_state("count_down", nullptr, nullptr, std::make_shared<HardMode>(nullptr, nullptr, state_machine));
    }

    if (world->update_scored(bird->get_collision_rect()))
    {
        ++score;
        Settings::sounds["score"].play();
    }
}

void HardMode::render(sf::RenderTarget &target) const noexcept
{
    world->render(target);
    bird->render(target);
    render_text(target, 20, 10, "Score: " + std::to_string(score), Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White);
}