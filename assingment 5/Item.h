//
// Created by Etienne on 28/03/2018.
//

#ifndef ASSINGMENT_5_ITEM_H
#define ASSINGMENT_5_ITEM_H

#include <string>
#include <map>


using std::string;

class Item {
public:
    Item() = default;

    ~Item() = default;

    Item(const Item& i);

    const string &getId() const;

    void setId(const string &id);

    const string &getType() const;

    void setType(const string &type);

    const string &getName() const;

    void setName(const string &name);

    double getPpu() const;

    void setPpu(double ppu);

    void addBatter(int id ,std::string batter );

    void addTopping(int id, std::string topping);

    const std::map<int,std::string>& getBatters();

    const std::map<int,std::string>& getToppings();

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
    std::map<int ,std::string> batters;
    std::map<int ,std::string> topping;
};


#endif //ASSINGMENT_5_ITEM_H
