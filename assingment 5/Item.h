//
// Created by Etienne on 28/03/2018.
//

#ifndef ASSINGMENT_5_ITEM_H
#define ASSINGMENT_5_ITEM_H

#include <string>


using std::string;

class Item {
public:
    Item() = default;

    ~Item() = default;

    Item(const Item& item);

    //Might change to map

    enum Batter{Regular=1001, Chocolat = 1002, Blueberry = 1003, DevilsFood = 1004};

    enum Topping{None=5001, Glazed=5002, Sugar=5005, PowderedSugar = 5007,
        ChocolatWithSprinkles=5006, ChocolatTopping = 5003, Maple = 5004};

    const string &getId() const;

    void setId(const string &id);

    const string &getType() const;

    void setType(const string &type);

    const string &getName() const;

    void setName(const string &name);

    double getPpu() const;

    void setPpu(double ppu);

    Batter getBatters() const;

    void setBatters(Batter batters);

    Topping getTopping() const;

    void setTopping(Topping topping);

    bool operator<(const Item &rhs) const;

    bool operator>(const Item &rhs) const;

    bool operator<=(const Item &rhs) const;

    bool operator>=(const Item &rhs) const;

private:
    string id;
    string type;
    string name;
    double ppu;

    //Enums
    Batter batters;
    Topping topping;
};


#endif //ASSINGMENT_5_ITEM_H
