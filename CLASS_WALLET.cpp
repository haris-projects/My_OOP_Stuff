#include<iostream>
using namespace std;

class Wallet{
    double balance;
    public:
    Wallet(double ba) : balance(ba){ }
    friend void Setbalance(Wallet &w1 ,Wallet &w2 , double amount);
    void showbalance();
};

void Setbalance(Wallet &w1 ,Wallet &w2 , double amount){
    w1.balance-=amount;
    w2.balance+=amount;
}
void Wallet::showbalance(){
    cout<<"Balance "<<balance<<endl;
}
int main(){
 
    Wallet w1(1000.0) , w2(200.0);
    Setbalance(w1 , w2 , 300);
    cout<<"Wallet 1 : ";
    w1.showbalance();
    cout<<endl;
    cout<<"Wallet 2 : ";
    w2.showbalance();


    return 0 ;
}