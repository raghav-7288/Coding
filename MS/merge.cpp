#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;
string solve(long long n)
{
    int p = 25;
    string res = "";
    while (n >= 1)
    {
        for (int i = p; i >= 0; i--)
        {
            int temp = 1 << p;
            if (temp > n)
            {
                p--;
            }
            else
            {
                char ch = 'a' + p;
                res = res + ch;
                n = n - temp;
                break;
            }
        }
    }
    return res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}