#include <bits/stdc++.h>
using namespace std;
class MyStack
{
private:
    queue<int> q1;

public:
    MyStack()
    {
    }
    void push(int x)
    {
        int k = q1.size();
        if (k == 0)
        {
            q1.push(x);
        }
        else
        {
            q1.push(x);
            for (int i = 0; i < k; i++)
            {
                int m = q1.front();
                q1.pop();
                q1.push(m);
            }
        }
    }
    int pop()
    {
        if (q1.empty())
            return -1;
        int m = q1.front();
        q1.pop();
        return m;
    }
    int top()
    {
        return q1.front();
    }
    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    return 0;
}