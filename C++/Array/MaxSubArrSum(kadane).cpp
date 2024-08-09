//max sum of a subarray
#include <bits/stdc++.h>
using namespace std;
int kadane(int n, vector<int> v)
{
    int sum = 0;
    int maxS = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        maxS = max(sum, maxS);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxS;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << kadane(n, v);
    return 0;
}