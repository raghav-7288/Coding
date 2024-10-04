#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    for (auto n : arr)
    {
        if (n % 2 == 0)
            ans += n;
    }
    cout << ans;
    return 0;
}