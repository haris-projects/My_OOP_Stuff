#include <iostream>
#include <string>
using namespace std;

class PatientRecord {
protected:
    double* vitalsHistory;
    int logCount;

public:
    PatientRecord(double v[], int n) {
        logCount = n;
        vitalsHistory = new double[logCount];
        for (int i = 0; i < logCount; i++) {
            vitalsHistory[i] = v[i];
        }
    }

    PatientRecord(const PatientRecord& p) {
        logCount = p.logCount;
        vitalsHistory = new double[logCount];
        for (int i = 0; i < logCount; i++) {
            vitalsHistory[i] = p.vitalsHistory[i];
        }
    }

    void display() {
        cout << "Vitals: ";
        for (int i = 0; i < logCount; i++) {
            cout << vitalsHistory[i] << " ";
        }
        cout << endl;
    }

    ~PatientRecord() {
        delete[] vitalsHistory;
        cout << "PatientRecord destructor called" << endl;
    }
};

class ICUPatientRecord : public PatientRecord {
private:
    string* alertMessages;
    int alertCount;
    int severityLevel;

public:
    ICUPatientRecord(double v[], int n, int s) : PatientRecord(v, n) {
        alertMessages = new string[n];
        alertCount = 0;
        severityLevel = s;
    }

    ICUPatientRecord(const ICUPatientRecord& p) : PatientRecord(p) {
        alertCount = p.alertCount;
        severityLevel = p.severityLevel;
        alertMessages = new string[logCount];
        for (int i = 0; i < alertCount; i++) {
            alertMessages[i] = p.alertMessages[i];
        }
    }

    void evaluateEmergencyStatus() {
        for (int i = 0; i < logCount; i++) {
            if (vitalsHistory[i] < 60) {
                alertMessages[alertCount] = "Low heart rate: " + to_string((int)vitalsHistory[i]);
                alertCount++;
            }
            else if (vitalsHistory[i] > 100) {
                alertMessages[alertCount] = "High heart rate: " + to_string((int)vitalsHistory[i]);
                alertCount++;
            }
        }
        if (alertCount >= 3) {
            severityLevel = 3;
        }
        else if (alertCount > 0) {
            severityLevel = 2;
        }
    }

    void display() {
        PatientRecord::display();
        cout << "Severity Level: " << severityLevel << endl;
        cout << "Alerts: " << alertCount << endl;
        for (int i = 0; i < alertCount; i++) {
            cout << alertMessages[i] << endl;
        }
    }

    ~ICUPatientRecord() {
        delete[] alertMessages;
        cout << "ICUPatientRecord destructor called" << endl;
    }
};

int main() {
    double vitals[] = {72, 55, 88, 120, 95, 101};

    ICUPatientRecord p1(vitals, 6, 1);
    p1.evaluateEmergencyStatus();
    cout << "--- Original ---" << endl;
    p1.display();

    ICUPatientRecord p2(p1);
    cout << "--- Copy ---" << endl;
    p2.display();

    return 0;
}