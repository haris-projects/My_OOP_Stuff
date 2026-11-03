#include<iostream>
using namespace std;

class Product{
private:
int id;
string name;
int price;
int qty;
public:
int totalValue()const;
string getname()const;
void sell(int n);
void display();
Product();
Product(int id , string name , int price , int qty){
this->id=id;
this->price=price;
this->qty=qty;
}

};
int main(){




    return 0 ;
}