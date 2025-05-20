#include <iostream>
#include <vector>
using namespace std;

class product 
{
protected:
    string name;
    double price;
public:
    product(string n, double p) : name(n), price(p) {}
    virtual double getPrice() const 
	{
        return price;
    }
    string getName() const 
	{
        return name;
    }
    virtual ~product()=default;
};

class DiscountedProduct : public product 
{
public:
	double price;
    DiscountedProduct(string n, double p) : product(n, p), price(p) {}

    double getPrice() const override 
	{
        return price;
    }

    void applyDis(double P) 
	{
        auto disCal=[P](double currentPrice) 
		{
            return currentPrice*(1-P/100.0);
        };
        price=disCal(price);
    }
};

int main() {
    vector<DiscountedProduct> products = {
        DiscountedProduct("Backpack", 1000.0),
        DiscountedProduct("Boots", 700.0),
        DiscountedProduct("Ball", 150.0)
    };

    products[0].applyDis(10);  
    products[1].applyDis(15);  
    products[2].applyDis(20);

    for (auto product : products) {
        cout<<"Product "<<product.getName()<<endl;
        cout<<"Original Price "<<product.product::getPrice()<<endl;  
        cout<<"Discounted Price "<<product.getPrice()<<endl;
        cout<<endl;
    }
}
