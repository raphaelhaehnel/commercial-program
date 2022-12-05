#include "Buyers.h"

using namespace std;


buyer::buyer(string name)
{
    b_name = name;
    b_paid = 0;
}


string buyer::getName() const
{
    return b_name;
}


void buyer::sell(std::string objet, int amount, std::string date)
{
    b_objet.push_back(objet);
    b_amount.push_back(amount);
    if (date.size()==9)
        date = "0" + date;
    b_date.push_back(date);
}


void buyer::pay(double money)
{
    b_paid += money;
}


double buyer::dues(vector<products*> const& productVector) const
{
    double r(0.0);

    for (unsigned short i=0; i < b_objet.size(); i++)
    {
        for (unsigned short j=0; j < productVector.size(); j++)
        {
            if (productVector[j]->getName() == b_objet[i])
            {
                r += (b_amount[i] * productVector[j]->getPrice());
            }
        }
    }

    return (r - b_paid);
}


double buyer::paid() const
{
    return b_paid;
}


int buyer::sellNumber() const
{
    return b_objet.size();
}


string buyer::getObjetName(int digit) const
{
    return b_objet[digit];
}


string buyer::getObjetDate(int digit) const
{
    return b_date[digit];
}


int buyer::getObjetAmount(int digit) const
{
    return b_amount[digit];
}

