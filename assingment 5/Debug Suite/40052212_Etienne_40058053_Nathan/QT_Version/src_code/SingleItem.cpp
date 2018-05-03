//
// Created by Natha on 2018-04-08.
//

#include "SingleItem.h"

SingleItem::SingleItem(string id,string type,string name,double ppu,std::pair<const int,std::string> batters,
std::pair<const int,std::string> topping){
    this->id=id;
    this->type=type;
    this->name=name;
    this->ppu=ppu;
    this->batters.first = batters.first;
    this->batters.second = batters.second;

    this->topping.first = topping.first;
    this->topping.second = topping.second;

}

const string &SingleItem::getId() const {
    return id;
}

void SingleItem::setId(const string &id) {
    SingleItem::id = id;
}

const string &SingleItem::getType() const {
    return type;
}

void SingleItem::setType(const string &type) {
    SingleItem::type = type;
}

const string &SingleItem::getName() const {
    return name;
}

void SingleItem::setName(const string &name) {
    SingleItem::name = name;
}

double SingleItem::getPpu() const {
    return ppu;
}

void SingleItem::setPpu(double ppu) {
    SingleItem::ppu = ppu;
}

const std::pair<int,std::string>& SingleItem::getBatters(){
    return batters;
}

const std::pair<int,std::string>& SingleItem::getToppings(){
    return topping;
}

bool SingleItem::operator<(const SingleItem &rhs) const {
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

bool SingleItem::operator>(const SingleItem &rhs) const {
    return rhs < *this;
}

bool SingleItem::operator<=(const SingleItem &rhs) const {
    return !(rhs < *this);
}

bool SingleItem::operator>=(const SingleItem &rhs) const {
    return !(*this < rhs);
}

SingleItem::SingleItem(const SingleItem &singleitem) {
    this->id=singleitem.id;
    this->name=singleitem.name;
    this->type=singleitem.type;
    this->ppu=singleitem.ppu;

    this->batters.first = singleitem.batters.first;
    this->batters.second = singleitem.batters.second;

    this->topping.first = singleitem.topping.first;
    this->topping.second = singleitem.topping.second;
}

