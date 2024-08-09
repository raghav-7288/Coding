#include <bits/stdc++.h>
using namespace std;
void countSort(vector<int> &a, int n, int k)
{
    vector<int> b(k + 1);
    vector<int> c(a.size());
    for (auto x : a)
    {
        b[x]++;
    }
    for (int i = 1; i < b.size(); i++)
    {
        b[i] = b[i] + b[i - 1];
    }
    for (int i = c.size() - 1; i > -1; i--)
    {
        c[b[a[i]] - 1] = a[i];
        b[a[i]]--;
    }
    for (auto x : c)
    {
        cout << x << " ";
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n, k;
    // range->[0,k]
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    countSort(a, n, k);
    return 0;
}