#include "GameEngine.h"
#include <iostream>

GameEngine::GameEngine() : isRunning(true) {
    Scene* boat = new Scene("You are in your boat. There is an exit leading north.");
    Scene* ocean = new Scene("You have dove into the deep scary Ocean. There is a faint light to the south.");
    Scene* beach = new Scene("You are on the beach where X marks the spot. The depths of the Ocean lie north.");

    boat->setExit("north", ocean);
    ocean->setExit("south", boat);
    ocean->setExit("north", beach);
    beach->setExit("south", ocean);

    boat->addItem(new Item("Boat Key"));
    ocean->addItem(new Item("Ocean Key"));

    scenes["Boat"] = boat;
    scenes["Ocean"] = ocean;
    scenes["Beach"] = beach;

    player.currentScene = boat;
}

GameEngine::~GameEngine() {
    for (auto& pair : scenes) {
        delete pair.second;
    }
}

void GameEngine::start() {
    std::cout << "Welcome to the Summer Adventure!" << std::endl;
    player.currentScene->describeScene();
    std::string input;
    while (isRunning) {
        std::cout << "> ";
        std::getline(std::cin, input);
        handleInput(input);
    }
}

void GameEngine::handleInput(const std::string& input) {
    if (input == "quit") {
        isRunning = false;
        std::cout << "Exiting game..." << std::endl;
    } else if (input == "look") {
        player.currentScene->describeScene();
    } else if (input.substr(0, 2) == "go") {
        std::string direction = input.substr(3);
        Scene* nextScene = player.currentScene->getExit(direction);
        if (nextScene) {
            player.moveToScene(nextScene);
            if (player.currentScene->description == "You are on the beach where X marks the spot. The depths of the Ocean lie north.") {
                if (player.hasItem("Boat Key") && player.hasItem("Ocean Key")) {
                    std::cout << "You have both keys and have reached the Treasure! You win!" << std::endl;
                    isRunning = false; // Optionally end the game after winning
                } else {
                    std::cout << "You have reached the X, but you don't have all the necessary keys to win." << std::endl;
                }
            }
        } else {
            std::cout << "You can't go that way." << std::endl;
        }
    } else if (input.substr(0, 4) == "take") {
        std::string itemName = input.substr(5);
        Item* item = player.currentScene->takeItem(itemName);
        if (item) {
            player.addItem(item);
            std::cout << "Taken " << itemName << "." << std::endl;
        } else {
            std::cout << "No such item here." << std::endl;
        }
    } else {
        std::cout << "Unknown command." << std::endl;
    }
}

void GameEngine::displayHelp() const {
    std::cout << "Available commands:" << std::endl;
    std::cout << "  help        - Show this help message" << std::endl;
    std::cout << "  look        - Describe the current scene" << std::endl;
    std::cout << "  go [dir]    - Move in the specified direction (north, south, east, west)" << std::endl;
    std::cout << "  take [item] - Take an item from the current scene" << std::endl;
    std::cout << "  inventory   - List all items in your inventory" << std::endl;
    std::cout << "  quit        - Exit the game" << std::endl;
}