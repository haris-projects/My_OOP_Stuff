#include <iostream>
using namespace std;

class Ticket {
private:
    string plateno;
    int hours;
    int serial;
    double vehiclefee;
    static int serialno;
    static int issued;
    static int active;
    static double revenue;
public:
    static void report();
    void fee();
    Ticket(string plate, int hours) : plateno(plate), hours(hours), vehiclefee(0) {
        serial = ++serialno;
        issued++;
        active++;
        fee();                      // calculate fee when ticket is created
    }
    ~Ticket() {
        active--;
        cout << "Total fee for car " << plateno << " (serial " << serial
             << ") is " << vehiclefee << endl;
    }
};

void Ticket::report() {
    cout << "Total Vehicle Issued : " << issued << endl;
    cout << "Total active vehicle : " << active << endl;
    cout << "Total revenue : " << revenue << endl;
}

void Ticket::fee() {
    if (hours == 1)
        vehiclefee = 50;
    else if (hours > 1)
        vehiclefee = 50 + 30;       // change this if your rule is different
    revenue += vehiclefee;
}

int Ticket::serialno = 0;
int Ticket::issued = 0;
int Ticket::active = 0;
double Ticket::revenue = 0;

int main() {
    Ticket t1("ABC-123", 3);
    Ticket t2("XYZ-789", 1);
    Ticket::report();
    Ticket t3("LHR-555", 5);
    Ticket::report();

    Ticket *p = new Ticket("PSH-001", 2);
    Ticket::report();
    delete p;

    return 0;
}