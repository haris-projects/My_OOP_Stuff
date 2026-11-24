#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Currency_amount {
public:
    string CurrencyCode;
    double amount;

    Currency_amount(string code, double amt) : CurrencyCode(code), amount(amt) {}

    // c1 + c2
    Currency_amount operator+(const Currency_amount &c2) const {
        if (CurrencyCode == c2.CurrencyCode) {
            return Currency_amount(CurrencyCode, amount + c2.amount);
        }
        cout << "Error!" << endl;
        return Currency_amount("ERR", 0.0);
    }

    // c1 - c2
    Currency_amount operator-(const Currency_amount &c2) const {
        if (CurrencyCode == c2.CurrencyCode) {
            return Currency_amount(CurrencyCode, amount - c2.amount);
        }
        cout << "Error!" << endl;
        return Currency_amount("ERR", 0.0);
    }

    // c1 += c2
    Currency_amount& operator+=(const Currency_amount &c2) {
        if (CurrencyCode == c2.CurrencyCode) {
            amount += c2.amount;
        }
        else {
            cout << "Error!" << endl;
        }
        return *this;
    }

    // c1 == c2
    bool operator==(const Currency_amount &c2) const {
        return CurrencyCode == c2.CurrencyCode &&
               fabs(amount - c2.amount) < 0.00001;
    }

    void Show() const {
        cout << "Country Code is : " << CurrencyCode << endl;
        cout << "Total Amount : " << amount << endl;
    }
};

int main() {
    string code;
    double amount;

    cout << "Enter Country Code For Object 1 : ";
    getline(cin, code);
    cout << "Enter Amount : ";
    cin >> amount;
    Currency_amount c1(code, amount);

    cin.ignore();
    cout << "Enter Country Code For Object 2 : ";
    getline(cin, code);
    cout << "Enter Amount : ";
    cin >> amount;
    Currency_amount c2(code, amount);

    cout << "\nShow Addition Calculation" << endl;
    Currency_amount c3 = c1 + c2;
    c3.Show();

    cout << "\nShow Subtraction Calculation" << endl;
    Currency_amount c4 = c1 - c2;
    c4.Show();

    cout << "\nShow c1+=c2 Calculation" << endl;
    c1 += c2;
    c1.Show();

    string anotherCode1, anotherCode2;
    double money1, money2;

    cout << "\nShow Result Of == Operator (true/false)" << endl;
    cin.ignore();
    cout << "Enter Code 1 : ";
    getline(cin, anotherCode1);
    cout << "Enter Money 1 : ";
    cin >> money1;

    cin.ignore();
    cout << "Enter Code 2 : ";
    getline(cin, anotherCode2);
    cout << "Enter Money 2 : ";
    cin >> money2;

    Currency_amount c5(anotherCode1, money1);
    Currency_amount c6(anotherCode2, money2);

    cout << "Result : " << (c5 == c6 ? "True" : "False") << endl;

    return 0;
}