#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    int accountno;
    string holdername;
    double balance;

public:
    Account() : accountno(0), holdername(""), balance(0) {}

    Account(int accountno, string holdername, double balance = 0) {
        this->accountno = accountno;
        this->holdername = holdername;
        this->balance = balance;
    }

    void deposit(double amount);
    void withdraw(double amount);
    void setHolder(string name);
    void display() const;
};

void Account::deposit(double amount) {
    if (amount <= 0) {
        cout << "Cannot deposit " << amount << endl;
        return;
    }
    balance += amount;
    cout << "You deposited " << amount << ". Total: " << balance << endl;
}

void Account::withdraw(double amount) {
    if (amount <= 0 || amount > balance) {
        cout << "Insufficient balance or invalid amount! Can't withdraw " << amount << endl;
        return;
    }
    balance -= amount;
    cout << "You withdrew " << amount << ". Total: " << balance << endl;
}

void Account::setHolder(string holdername) {
    this->holdername = holdername;
}

void Account::display() const {
    cout << "Account No: " << accountno << endl;
    cout << "Account Holder: " << holdername << endl;
    cout << "Balance: " << balance << endl;
}

int main() {
    Account a1(3014, "Haris Iqbal", 15000000);
    a1.display();

    Account a2;
    a2.display();

    a1.deposit(2400000);
    a1.deposit(-1200);
    a1.withdraw(1900000);
    a1.withdraw(1590);

    a2.setHolder("Sara Noor");
    a2.display();

    Account *p = new Account;
    p->deposit(134000);
    delete p;

    const Account a3(1003, "Khan", 50);
    a3.display();

    return 0;
}