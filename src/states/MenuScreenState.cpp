#include <src/states/MenuScreenState.hpp>

#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/MenuScreenState.hpp>
#include <src/modes/NormalMode.hpp>
#include <src/modes/HardMode.hpp>
#include <iostream>

MenuScreenState::MenuScreenState(StateMachine *sm) noexcept
    : BaseState{sm}, world{}, options{{MenuOptions::NormalModeOption, MenuOptions::HardModeOption}}, selected{0}
{
}

void MenuScreenState::handle_inputs(const sf::Event &event) noexcept
{
    if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
    {
        selected = selected > 0 ? (selected-1) : selected;
    } else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S) {
        selected = selected < (options.size()-1) ? (selected+1) : selected;
    } else if (event.key.code == sf::Keyboard::Enter || (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)) {
        std::shared_ptr<BaseGameMode> mode = nullptr;
        if (options[selected] == MenuOptions::NormalModeOption)
            mode = std::make_shared<NormalMode>(nullptr, nullptr, state_machine);
        else if (options[selected] == MenuOptions::HardModeOption)
            mode = std::make_shared<HardMode>(nullptr, nullptr, state_machine);

        state_machine->change_state("count_down", nullptr, nullptr, mode);
    }
}

void MenuScreenState::update(float dt) noexcept
{
    world.update(dt); 
}

void MenuScreenState::render(sf::RenderTarget &target) const noexcept
{
    world.render(target);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 3, "Menu", Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White, true);
    for (size_t i = 0; i < options.size(); i++)
    {
        auto current_option = selected == i ? (">"+options[i]): options[i];
        render_text(target, Settings::VIRTUAL_WIDTH / 2, (2 * Settings::VIRTUAL_HEIGHT / 3) + ((i+1)*Settings::MEDIUM_TEXT_SIZE), current_option, Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::White, true);
    }
}