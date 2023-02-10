#pragma once

#include <src/modes/BaseGameMode.hpp>

class HardMode : public BaseGameMode
{
public:
    HardMode(std::shared_ptr<Bird> _bird = nullptr, std::shared_ptr<World> _world = nullptr, StateMachine* _sm = nullptr);
};
