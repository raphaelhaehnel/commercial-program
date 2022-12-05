#ifndef BUYERS_H
#define BUYERS_H



#include <string>
#include <vector>
#include <sstream>
#include "Products.h"



template<typename T>
std::string anyToString(const T& t)
{
    std::ostringstream ss;
    ss << t;
    return ss.str();
}


class buyer
{
    public:
        buyer(std::string name);
        std::string getName() const;
        void sell(std::string objet, int amount, std::string date);
        void pay(double money);
        double dues(std::vector<products*> const& productVector) const;
        double paid() const;
        int sellNumber() const;
        std::string getObjetName(int digit) const;
        std::string getObjetDate(int digit) const;
        int getObjetAmount(int digit) const;

    private:
        std::string b_name;
        std::vector<std::string> b_objet;
        std::vector<int> b_amount;
        std::vector<std::string> b_date;
        double b_paid;


};


#endif // BUYERS_H

