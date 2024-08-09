#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
class Stack
{
    int top;

public:
    int a[MAX];
    Stack() { top = -1; }
    bool push(int x)
    {
        if (top >= (MAX - 1))
        {
            cout << "Stack Overflow";
            return false;
        }
        else
        {
            a[++top] = x;
            cout << x << " pushed into stack\n";
            return true;
        }
    }
    int pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow";
            return 0;
        }
        else
        {
            int x = a[top--];
            return x;
        }
    }
    int st_top()
    {
        if (top < 0)
        {
            cout << "Stack is Empty";
            return 0;
        }
        else
        {
            int x = a[top];
            return x;
        }
    }
    bool isEmpty()
    {
        return (top < 0);
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";
    cout << "Top element is : " << s.st_top() << endl;
    cout << "Elements present in stack : ";
    while (!s.isEmpty())
    {
        cout << s.st_top() << " ";
        s.pop();
    }
    return 0;
}