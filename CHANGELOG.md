# Changelog

Flappy bird game.

## [main]

-The main branch contains a working version of the flappy bird game, allowing the user to select the normal and hard mode, this last one allowing the user to move forward and backward with the arrow keys and catch power ups sometimes as it's buggy at the moment.
-Both modes allow the user to pause the game with the space bar.
-The bird jumps with the left button of the mouse.

-The hard mode specifications were made in src/modes/HardMode.hpp and src/modes/HardMode.cpp.
-The modes menu's logic is in src/modes/MenuScreenState.hpp and src/modes/MenuScreenState.cpp.
-Additional modifications were made in the classes Bird, World, PlayingState.
-The power up class is in src/modes/PowerUp.hpp and src/modes/PowerUp.cpp.
-New sounds and constants were added to Settings.hpp and Settings.cpp. 