#include "Scene.h"

Scene::~Scene() {
    for (Item* item : items) {
        delete item;
    }
}

void Scene::describeScene() const {
    std::cout << description << std::endl;
    for (const Item* item : items) {
        std::cout << "There is a " << item->getName() << " here." << std::endl;
    }
}

void Scene::setExit(const std::string& direction, Scene* scene) {
    exits[direction] = scene;
}

Scene* Scene::getExit(const std::string& direction) const {
    auto it = exits.find(direction);
    if (it != exits.end()) {
        return it->second;
    }
    return nullptr;
}

void Scene::addItem(Item* item) {
    items.push_back(item);
}

Item* Scene::takeItem(const std::string& itemName) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getName() == itemName) {
            Item* item = *it;
            items.erase(it);
            return item;
        }
    }
    return nullptr;
}
