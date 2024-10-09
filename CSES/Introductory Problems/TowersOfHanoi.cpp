#include <bits/stdc++.h>
using namespace std;
// from to left to mid using r
void solve(int n, int l, int r, int m)
{
    if (n == 1)
    {
        cout << l << " " << r << endl;
        return;
    }
    solve(n - 1, l, m, r);
    solve(1, l, r, m);
    solve(n - 1, m, r, l);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    long long m = pow(2, n) - 1;
    cout << m << endl;
    solve(n, 1, 3, 2);
    return 0;
}