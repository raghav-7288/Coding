#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = 0, left = 0, right = 0, curr = 0;
    while (right < n)
    {
        curr += arr[right];
        while (curr > target)
        {
            curr -= arr[left];
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }
    cout << ans;
    return 0;
}