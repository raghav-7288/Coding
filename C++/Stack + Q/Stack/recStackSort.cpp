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
void insertInStack(int val, stack<int> &st)
{
    if (st.empty())
    {
        st.push(val);
    }
    else
    {
        if (st.top() < val)
        {
            st.push(val);
        }
        else
        {
            int top = st.top();
            st.pop();
            insertInStack(val, st);
            st.push(top);
        }
    }
}
void sortStack(stack<int> &st)
{
    if (st.empty())
        return;
    int top = st.top();
    st.pop();
    sortStack(st);
    insertInStack(top, st);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    stack<int> st;
    st.push(1);
    st.push(4);
    st.push(3);
    st.push(5);
    st.push(2);
    print(st);
    sortStack(st);
    print(st);

    return 0;
}