#include<iostream>
#include<string>
using namespace std;

class Bank{
protected:
    string accountno;
    double balance;
public:
    Bank(string ac, double ba) : accountno(ac), balance(ba) { }
};

class SavingAccount : protected Bank{
private:
    float interestRate;
public:
    SavingAccount(string acno, double bal, float rate) : Bank(acno, bal){
        interestRate = rate;
    }
    void display();
};

void SavingAccount::display(){
    cout<<"Account no Protected : "<<"*********"<<endl;
    cout<<"Balance : "<<balance<<endl;
    balance += balance * interestRate / 100;      // rate is a percentage
    cout<<"Interest Rate : "<<interestRate<<"%"<<endl;
    cout<<"Balance after interest : "<<balance<<endl;
}

class CurrentAccount : protected Bank{
private:
    double overDraftlimit = 0;
    double withdr = 0;
public:
    CurrentAccount(string acc, double bal) : Bank(acc, bal){ }
    void withDraw();
    void display();
};

void CurrentAccount::withDraw(){
    cout<<"Enter overdraft Limit : ";
    cin>>overDraftlimit;
    cout<<"Enter Withdraw Amount : ";
    cin>>withdr;

    if(withdr <= overDraftlimit + balance){
        balance -= withdr;                        // actually update balance
        cout<<"Your Current Amount is : "<<balance<<endl;
    }
    else{
        cout<<"Withdraw is over limit, can't process"<<endl;
    }
}

void CurrentAccount::display(){
    cout<<"Account no Protected : "<<"********"<<endl;
    cout<<"Total Balance : "<<balance<<endl;
}

int main(){
    SavingAccount s1("238!@#&*", 56000, 2.014);
    CurrentAccount c1("786&*5976@#$", 65899);

    s1.display();
    cout<<endl;

    c1.withDraw();
    c1.display();

    return 0;
}