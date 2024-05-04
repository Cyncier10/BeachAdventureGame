#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    std::string name;

    Item(std::string name) : name(name) {}
    std::string getName() const { return name; }
};

#endif
