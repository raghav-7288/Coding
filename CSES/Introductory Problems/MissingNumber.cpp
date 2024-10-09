#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int x = n;
    for (int i = 0; i < n - 1; i++)
    {
        int a;
        cin >> a;
        x ^= a;
        x ^= (i + 1);
    }
    cout << x;
    return 0;
}