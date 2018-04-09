//
// Created by Natha on 2018-04-08.
//

#ifndef ASSINGMENT_5_SINGLEITEM_H
#define ASSINGMENT_5_SINGLEITEM_H
#include <string>

using std::string;

class SingleItem {
private:
    std::string id;
    std::string type;
    std::string name;
    double ppu;
    std::pair<int,std::string> batters;
    std::pair<int,std::string> topping;
public:
    SingleItem(string id,string type,string name,double ppu,std::pair<const int,std::string> batters,
    std::pair<const int,std::string> topping);

    ~SingleItem() = default;

    SingleItem(const SingleItem& i);

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::string &getType() const;

    void setType(const std::string &type);

    const std::string &getName() const;

    void setName(const std::string &name);

    double getPpu() const;

    void setPpu(double ppu);

    const std::pair<int,std::string>& getBatters();

    const std::pair<int,std::string>& getToppings();

    bool operator<(const SingleItem &rhs) const;

    bool operator>(const SingleItem &rhs) const;

    bool operator<=(const SingleItem &rhs) const;

    bool operator>=(const SingleItem &rhs) const;

};


#endif //ASSINGMENT_5_SINGLEITEM_H
