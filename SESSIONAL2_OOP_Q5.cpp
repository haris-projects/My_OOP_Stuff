#include <iostream>
using namespace std;

class Arr {
    int* d;
    int n;
    char tag;
public:
    Arr(char t = 'Z', int size = 2) : n(size), tag(t) {
        d = new int[n];
        for (int i = 0; i < n; i++) d[i] = i * n;
        cout << "C" << tag << " ";
    }
    Arr(const Arr& o) : n(o.n), tag(o.tag + 1) {
        d = new int[n];
        for (int i = 0; i < n; i++) d[i] = o.d[n - 1 - i];
        cout << "K" << tag << " ";
    }
    void bump(int k) { for (int i = 0; i < n; i++) d[i] += k + i; }
    int sum() const { int s = 0; for (int i = 0; i < n; i++) s += d[i]; return s; }
    void show() const {
        cout << tag << "[";
        for (int i = 0; i < n; i++) cout << d[i] << (i < n - 1 ? "," : "");
        cout << "] ";
    }
    ~Arr() { cout << "D" << tag << " "; delete[] d; }
};

int main() {
    cout << "Q1: ";
    {
        Arr a('A', 3);
        Arr b(a);
        b.bump(2);
        a.show(); b.show();
        cout << a.sum() + b.sum() << " ";
    }
    cout << endl;
    return 0;
}