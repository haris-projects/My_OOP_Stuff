#include<iostream>
#include<string>
using namespace std;

class bank{
    private :
  double balance;
  string accountHolder;
  double withdraw;
  public:
//  void deposite(double d , string h);
//  void withdraw(double w);
 void deposite(double d , string h){
    balance=d;
    accountHolder=h;
    cout<<" "<<accountHolder<<" your total Deposite Amount is "<<balance<<endl;
 }
void  Withdraw(double w ){
    withdraw=w;
    
    if(withdraw>balance)
    cout<<"Insufficient balance "<<endl ;
    else{
 cout<<" "<<accountHolder<<" you want to WithdraW "<<withdraw <<" From Your Account :"<<endl;
  balance-=withdraw;
    
  cout<<"Now Your total Amount in a account is "<<balance<<endl;
    }
 }

};

int main(){
 bank b1;
 double am , dep;
 cout<<"Enter Deposite Amount ";
 cin>>am;

 cout<<"Enter Withdraw Amount ";
 cin>>dep;
 b1.deposite(am,"HARIS IQBAL");
 b1.Withdraw(dep);




    return 0;
}