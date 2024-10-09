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
    if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    int start = n & 1 ? 1 : 2, _n = n;
    while (_n--)
    {
        cout << start << " ";
        start += 2;
        if (start > n)
        {
            start = (start & 1 ? 2 : 1);
        }
    }
    return 0;
}