#include <bits/stdc++.h>
using namespace std;
void print(stack<int> st)
{
    cout << endl;
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
void insertBottom(int a, stack<int> &st)
{
    if (st.empty())
    {
        st.push(a);
    }
    else
    {
        int top = st.top();
        st.pop();
        insertBottom(a, st);
        st.push(top);
    }
}
void reverseStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    else
    {
        int top = st.top();
        st.pop();
        reverseStack(st);
        insertBottom(top, st);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(6);
    print(st);
    reverseStack(st);
    print(st);

    return 0;
}