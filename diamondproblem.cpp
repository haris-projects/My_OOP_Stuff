#include <iostream>
using namespace std;

class A
{
protected:
    int x;

public:
    A(int n) : x(n)
    {
        cout << "A(" << x << ")\n";
    }

    virtual void show()
    {
        cout << "A::show() x = " << x << endl;
    }

    virtual int calculate()
    {
        return x * 2;
    }
};

class B : virtual public A
{
protected:
    int x;

public:
    B(int n) : A(n + 1), x(n)
    {
        cout << "B(" << x << ")\n";
    }

    void show() override
    {
        cout << "B::show() x = " << x << endl;
    }

    int calculate() override
    {
        return A::calculate() + x;
    }
};

class C : virtual public A
{
protected:
    int x;

public:
    C(int n) : A(n + 2), x(n * 2)
    {
        cout << "C(" << x << ")\n";
    }

    void show() override
    {
        cout << "C::show() x = " << x << endl;
    }

    int calculate() override
    {
        return A::calculate() - x;
    }
};

class D : public B, public C
{
private:
    int x;

public:
    D(int n)
        : A(n + 10), B(n + 1), C(n + 2), x(n * 3)
    {
        cout << "D(" << x << ")\n";
    }

    void show() override
    {
        cout << "D::show() x = " << x << endl;
    }

    int calculate() override
    {
        return B::calculate() + C::calculate() + x;
    }

    void challenge()
    {
        cout << "\n--- CHALLENGE ---\n";

        cout << "1. x = " << x << endl;
        cout << "2. B::x = " << B::x << endl;
        cout << "3. C::x = " << C::x << endl;
        cout << "4. A::x = " << A::x << endl;

        cout << "5. calculate = " << calculate() << endl;

        A* ptr = this;

        cout << "6. ";
        ptr->show();

        cout << "7. A::show(): ";
        A::show();

        cout << "8. B::show(): ";
        B::show();

        cout << "9. C::show(): ";
        C::show();
    }
};

int main()
{
    D obj(5);

    cout << "\n===== OUTPUT QUESTIONS =====\n";

    obj.challenge();

    cout << "\n===== POLYMORPHISM =====\n";

    B* bptr = &obj;
    C* cptr = &obj;

    bptr->show();
    cptr->show();

    cout << "\nB calculate = " << bptr->calculate() << endl;
    cout << "C calculate = " << cptr->calculate() << endl;

    return 0;
}