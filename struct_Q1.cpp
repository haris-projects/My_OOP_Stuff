#include<iostream>
using namespace std;
struct item{
    string name;
    int quantity;
    float price ;
};
int main(){

item t1;
item *p=&t1;

cout<<"Please Enter Name Of Item ";
getline(cin,p->name);
cout<<"Enter Quantity of Amount ";
cin>>p->quantity;
cout<<"Enter Price of Items ";
cin>>p->price;

cout<<"The Name Of the item is :"<<p->name<<endl;
cout<<"The Total Quantity is :"<<p->quantity<<endl;
cout<<"The Price of the item is "<<p->quantity<<endl;



    return 0 ;
}