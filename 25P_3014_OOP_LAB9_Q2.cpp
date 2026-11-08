#include <iostream>
#include <string>
using namespace std;

class CoreTradingEngine {
protected:
    double orderVolume;
    string assetSymbol;

public:
    CoreTradingEngine(double v, string s) {
        orderVolume = v;
        assetSymbol = s;
    }

    void executeOrder(double price) {
        cout <<"Order executed: "<< orderVolume <<" units of "<< assetSymbol
             <<" at price "<<price << endl;
    }
};

class EncryptedRiskEngine : private CoreTradingEngine {
protected:
    bool validateRiskThreshold(double price) {
        double total = price * orderVolume;
        if (total <= 500000) {
            return true;
        }
        return false;
    }

public:
    EncryptedRiskEngine(double v, string s) : CoreTradingEngine(v, s) {
    }

    void processSecureTrade(double price, double volatilityScore) {
        cout << "Processing secure trade..." << endl;
        if (volatilityScore > 7) {
            cout <<"Trade rejected: volatility too high"<< endl;
            return;
        }
        if (validateRiskThreshold(price)) {
            cout <<"Risk validation passed"<< endl;
            executeOrder(price);
        }
        else {
            cout <<"Trade rejected: risk threshold exceeded"<< endl;
        }
    }
};

class HighFrequencyBot : public EncryptedRiskEngine {
public:
    HighFrequencyBot(double v, string s) : EncryptedRiskEngine(v, s) {
    }

    void explainAccess() {
        cout <<"EncryptedRiskEngine inherits CoreTradingEngine PRIVATELY."<< endl;
        cout <<"So executeOrder() and orderVolume become private inside EncryptedRiskEngine."<< endl;
        cout <<"Private members are not visible to child classes."<< endl;
        cout <<"So HighFrequencyBot cannot call executeOrder() directly (compiler error)."<< endl;
        cout <<"It can only reach it through processSecureTrade()."<< endl;
    }

    void runBot(double price, double volatilityScore) {
        cout << "Bot is running" << endl;
        processSecureTrade(price, volatilityScore);
    }

    void checkRisk(double price) {
        if (validateRiskThreshold(price)) {
            cout <<"Risk check passed"<< endl;
        }
        else {
            cout <<"Risk check failed"<< endl;
        }
    }
};

int main() {
    HighFrequencyBot bot(100, "AAPL");

    cout <<"===== Why direct call is blocked ====="<< endl;
    bot.explainAccess();

    cout <<"\n===== Direct call on plain CoreTradingEngine (no risk check) ====="<< endl;
    CoreTradingEngine rawEngine(100, "AAPL");
    rawEngine.executeOrder(6000);

    cout <<"\n===== Direct call on bot ====="<< endl;
    cout <<"bot.executeOrder(6000) -> compiler error, not accessible"<< endl;

    cout <<"\n===== Secure workflow: normal trade ====="<< endl;
    bot.runBot(150, 3);

    cout <<"\n===== Secure workflow: high volatility ====="<< endl;
    bot.runBot(150, 9);

    cout <<"\n===== Secure workflow: risk too high ====="<< endl;
    bot.runBot(6000, 2);

    cout <<"\n===== Risk check only ====="<< endl;
    bot.checkRisk(150);

    return 0;
}