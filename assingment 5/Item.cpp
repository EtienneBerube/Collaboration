//
// Created by Etienne on 28/03/2018.
//

#include "Item.h"

const string &Item::getId() const {
    return id;
}

void Item::setId(const string &id) {
    Item::id = id;
}

const string &Item::getType() const {
    return type;
}

void Item::setType(const string &type) {
    Item::type = type;
}

const string &Item::getName() const {
    return name;
}

void Item::setName(const string &name) {
    Item::name = name;
}

double Item::getPpu() const {
    return ppu;
}

void Item::setPpu(double ppu) {
    Item::ppu = ppu;
}

void Item::addBatter(int id ,std::string batter ){
    this->batters.insert(std::pair<int,std::string>(id,batter));
}

void Item::addTopping(int id, std::string topping){
    this->topping.insert(std::pair<int,std::string>(id,topping));
}

std::map<int,std::string>& Item::getBatters(){
    return batters;
}

std::map<int,std::string>& Item::getToppings(){
    return topping;
}

bool Item::operator<(const Item &rhs) const {
    //TODO may change for comparator
    if (id < rhs.id)
        return true;
    if (rhs.id < id)
        return false;
    if (type < rhs.type)
        return true;
    if (rhs.type < type)
        return false;
    if (name < rhs.name)
        return true;
    if (rhs.name < name)
        return false;
    if (ppu < rhs.ppu)
        return true;
    if (rhs.ppu < ppu)
        return false;
    if (batters < rhs.batters)
        return true;
    if (rhs.batters < batters)
        return false;
    return topping < rhs.topping;
}

bool Item::operator>(const Item &rhs) const {
    return rhs < *this;
}

bool Item::operator<=(const Item &rhs) const {
    return !(rhs < *this);
}

bool Item::operator>=(const Item &rhs) const {
    return !(*this < rhs);
}

Item::Item(const Item &item) {
    this->id=item.id;
    this->name=item.name;
    this->type=item.type;
    this->ppu=item.ppu;
    this->batters=item.batters;
    this->topping=item.topping;
}

