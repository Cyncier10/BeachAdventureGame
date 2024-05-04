#ifndef PLAYER_H
#define PLAYER_H

#include "Scene.h"
#include <vector>

class Player {
public:
    Scene* currentScene;
    std::vector<Item*> inventory;

    void moveToScene(Scene* scene);
    void addItem(Item* item);
    bool hasItem(const std::string& itemName) const;
};

#endif
