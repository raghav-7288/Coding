#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        long long r, c;
        cin >> r >> c;
        long long b = max(r, c), s = min(r, c), diff = b - s;
        long long d = b * b - b + 1;

        if (b % 2)
        {
            if (b == r)
                diff *= -1;
            cout << d + diff << endl;
        }
        else
        {
            if (b == c)
                diff *= -1;
            cout << d + diff << endl;
        }
    }
    return 0;
}
