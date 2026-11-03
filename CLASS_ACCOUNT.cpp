#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string owner;
    double balance;

public:
       Account(string o, double b) {
        owner = o;
        balance = b;
    }

   
    double getBalance() const {
        return balance;
    }

  
    string getOwner() const {
        return owner;
    }

    // Non-const member function: modifies data
    void setBalance(double b) {
        balance = b;
    }
};

int main() {
    
    const Account myAccount("Haris", 5000);

    cout << "Account Owner: " << myAccount.getOwner() << endl;
    cout << "Account Balance: " << myAccount.getBalance() << endl;

    // NOT ALLOWED:
    // myAccount.setBalance(7000);

    // This fails to compile because myAccount is const.
    // setBalance() is non-const and may modify the object.

    return 0;
}