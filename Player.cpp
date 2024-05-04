#include "Player.h"
#include <iostream>

void Player::moveToScene(Scene* scene) {
    currentScene = scene;
    std::cout << "Moving to " << scene->description << std::endl;
    scene->describeScene();
}

void Player::addItem(Item* item) {
    inventory.push_back(item);
}

bool Player::hasItem(const std::string& itemName) const {
    for (const Item* item : inventory) {
        if (item->getName() == itemName) {
            return true;
        }
    }
    return false;
}
