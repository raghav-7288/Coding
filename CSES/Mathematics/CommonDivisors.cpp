#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, MAX = 1e6;
    cin >> n;
    vector<int> arr(n), freq(MAX + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    int ans = 1;
    for (int gcd = MAX; gcd >= 1; gcd--)
    {
        int count = 0;
        for (int multiple = gcd; multiple <= MAX; multiple += gcd)
        {
            count += freq[multiple];
            if (count >= 2)
            {
                cout << gcd;
                return 0;
            }
        }
    }
    return 0;
}