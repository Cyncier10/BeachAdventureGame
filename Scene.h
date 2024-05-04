#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Item.cpp"

class Scene {
public:
    std::string description;
    std::map<std::string, Scene*> exits;
    std::vector<Item*> items;

    Scene(std::string desc) : description(desc) {}
    ~Scene();
    void describeScene() const;
    void setExit(const std::string& direction, Scene* scene);
    Scene* getExit(const std::string& direction) const;
    void addItem(Item* item);
    Item* takeItem(const std::string& itemName);
};

#endif
