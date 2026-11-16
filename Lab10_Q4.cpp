#include <iostream>
#include <string>
using namespace std;

class LoanAccount;   

class SavingsAccount {
private:
    int customerID;
    double balance;          
    int monthsActive;       

public:
    SavingsAccount(int id, double bal, int months)
        : customerID(id), balance(bal), monthsActive(months) {}

    void deposit(double amt) { balance += amt; }
    friend void auditCustomerRisk(const SavingsAccount&, const LoanAccount&);
};

class LoanAccount {
private:
    int customerID;
    double loanAmount;       
    int missedPayments;     

public:
    LoanAccount(int id, double amt, int missed)
        : customerID(id), loanAmount(amt), missedPayments(missed) {}

    friend void auditCustomerRisk(const SavingsAccount&, const LoanAccount&);
};

void auditCustomerRisk(const SavingsAccount& s, const LoanAccount& l) {
    if (s.customerID != l.customerID) {
        cout << "Audit failed: accounts belong to different customers!\n";
        return;
    }

    int score = 700;  
    double ratio = (s.balance > 0) ? l.loanAmount / s.balance : 999;
    if (ratio > 5)      score -= 150;
    else if (ratio > 2) score -= 80;
    else if (ratio > 1) score -= 30;
    else                score += 30;
    score -= l.missedPayments * 40;
    if (s.monthsActive >= 24) score += 20;

    string risk;
    if (score >= 700)      risk = "LOW";
    else if (score >= 550) risk = "MEDIUM";
    else                   risk = "HIGH";

    cout << "---- Audit for Customer " << s.customerID << " ----\n";
    cout << "Savings balance : " << s.balance << "\n";
    cout << "Loan amount     : " << l.loanAmount << "\n";
    cout << "Missed payments : " << l.missedPayments << "\n";
    cout << "Debt/Savings    : " << ratio << "\n";
    cout << "Credit score    : " << score << "\n";
    cout << "Risk level      : " << risk << "\n\n";
}

int main() {
    SavingsAccount s1(101, 50000, 36);
    LoanAccount    l1(101, 20000, 0);
    auditCustomerRisk(s1, l1);          

    SavingsAccount s2(102, 3000, 6);
    LoanAccount    l2(102, 40000, 3);
    auditCustomerRisk(s2, l2);         

    SavingsAccount s3(103, 10000, 12);
    LoanAccount    l3(104, 5000, 1);
    auditCustomerRisk(s3, l3);          

    return 0;
}