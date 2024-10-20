// Find Smallest Missing Positive Number
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &a : arr)
        cin >> a;
    for (int i = 0; i < n; i++)
    {
        while (arr[i] >= 1 && arr[i] <= n && arr[i] != arr[arr[i] - 1])
        {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (arr[i - 1] != i)
        {
            cout << i;
            break;
        }
    }
    return 0;
}