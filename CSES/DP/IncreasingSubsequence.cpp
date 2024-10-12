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
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (arr.empty())
        {
            arr.push_back(a);
        }
        else
        {
            if (a > arr.back())
                arr.push_back(a);
            else
            {
                int pos = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
                arr[pos] = a;
            }
        }
    }
    cout << arr.size();
    return 0;
}