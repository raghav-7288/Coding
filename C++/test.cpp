#include <bits/stdc++.h>
using namespace std;
int longestSubarrayWithSumK(vector<int> &a, int k)
{
    map<int, int> mp;
    int n = a.size();
    int sum = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum == k)
        {
            len = max(len, i + 1);
        }
        if (mp.find(sum - k) != mp.end())
        {
            len = max(len, i - mp[sum - k]);
        }
        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
    }
    return len;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << longestSubarrayWithSumK(a, k);
    return 0;
}