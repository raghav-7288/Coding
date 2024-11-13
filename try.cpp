#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;
int rev(int n)
{
    int res = 0;
    while (n)
    {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}
bool ok(int i)
{
    int r = rev(i);
    if ((int)(sqrt(i + r)) == sqrt(i + r))
        return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int ans = 0;
    for (int i = 10; i < 100; i++)
    {
        if (ok(i))
            cout << i << " ";
    }
    return 0;
}