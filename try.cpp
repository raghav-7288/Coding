#include <bits/stdc++.h>
using namespace std;
class Base
{
public:
    virtual void Foo() { printf("Base::Foo()\n"); }
};

class Derived1 : public Base
{
public:
    void Foo() override { printf("Derived1::Foo()\n"); }
};

class Derived2 : public Base
{
public:
    void Foo() override { printf("Derived2::Foo()\n"); }
};

class Derived3 : public Derived1
{
public:
    void Foo() { printf("Derived3::Foo()\n"); }
};

void callFoo(Base *base)
{
    Derived1 *derived1 = dynamic_cast<Derived1 *>(base);
    Derived2 *derived2 = dynamic_cast<Derived2 *>(base);
    Derived3 *derived3 = dynamic_cast<Derived3 *>(base);

    if (base)
    {
        base->Foo();
    }
    if (derived1)
    {
        derived1->Foo();
    }
    if (derived2)
    {
        derived2->Foo();
    }
    if (derived3)
    {
        derived3->Foo();
    }
}

int main()
{
    Derived3 d;
    callFoo(static_cast<Base *>(&d));
    return 0;
}
