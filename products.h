#ifndef PRODUCTS_H
#define PRODUCTS_H


#include <string>


class products
{
    public:
        products(std::string name, double price = 0., int amount = 0);
        void increasingAmout(int add);
        void sell(int fewer);
        std::string getName() const;
        double getPrice() const;
        int getAmount() const;
        void setPrice(double p);
        void setAmount(int a);

    private:
        std::string p_name;
        double p_price;
        int p_amount;


};

#endif // PRODUCTS_H
