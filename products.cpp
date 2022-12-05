#include "Products.h"

using namespace std;


products::products(string name, double price, int amount)
{
    p_name = name;
    p_price = price;
    p_amount = amount;

}


void products::increasingAmout(int add)
{
    p_amount += add;
}


void products::sell(int fewer)
{
    p_amount -= fewer;
}


string products::getName() const
{
    return p_name;
}

double products::getPrice() const
{
    return p_price;
}


int products::getAmount() const
{
    return p_amount;
}


void products::setPrice(double p)
{
    p_price = p;
}


void products::setAmount(int a)
{
    p_amount = a;
}


