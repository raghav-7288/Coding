#include <bits/stdc++.h>
using namespace std;
/*
["2","1","+","3","*"] -> 9
["4","13","5","/","+"] -> 6
["10","6","9","3","+","-11","*","/","*","17","+","5","+"] -> 22
["4","3","-"] -> 1
*/
bool isNum(string s)
{
    if (s.back() >= 48 && s.back() <= 57)
        return true;
    return false;
}
int toNum(string s)
{
    int sign = 1, i = 0, n = 0;
    if (s[0] == '-')
    {
        sign = -1;
        i++;
    }
    while (i < s.length())
    {
        n = n * 10 + (s[i] - '0');
        i++;
    }
    return sign * n;
}
int evalRPN(vector<string> &tokens)
{
    int ans = 0, i = 0;
    stack<int> st;
    while (i < tokens.size())
    {
        if (isNum(tokens[i]))
        {
            int x = toNum(tokens[i]);
            st.push(x);
        }
        else
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            if (tokens[i] == "+")
                st.push(op1 + op2);
            else if (tokens[i] == "-")
                st.push(op1 - op2);
            else if (tokens[i] == "*")
                st.push(op1 * op2);
            else
                st.push(op1 / op2);
        }
        i++;
    }
    return st.top();
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}