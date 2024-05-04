#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Player.h"
#include <map>
#include <string>

class GameEngine {
private:
    bool isRunning;
    Player player;
    std::map<std::string, Scene*> scenes;

public:
    GameEngine();
    ~GameEngine();
    void start();
    void handleInput(const std::string& input);
    void displayHelp() const;  // Method to display help information
};

#endif
