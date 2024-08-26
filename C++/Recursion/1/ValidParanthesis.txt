// All valid paranthesisations of length n
#include <bits/stdc++.h>
using namespace std;
void validParen(int n, int len, vector<string> &res, string &str, int sumO, int sumC)
{
    if (len == n)
    {
        res.push_back(str);
        return;
    }
    if (sumO < n / 2)
    {
        str.push_back('(');
        validParen(n, len + 1, res, str, sumO + 1, sumC);
        str.pop_back();
    }
    if (sumC < sumO)
    {
        str.push_back(')');
        validParen(n, len + 1, res, str, sumO, sumC + 1);
        str.pop_back();
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    n -= n % 2;
    // cout << n;
    vector<string> res;
    string str;
    validParen(n, 0, res, str, 0, 0);
    for (auto x : res)
    {
        cout << x << endl;
    }
    return 0;
}