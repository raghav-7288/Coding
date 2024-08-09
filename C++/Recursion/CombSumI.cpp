#include <bits/stdc++.h>
using namespace std;
void solve(int n, vector<int> &arr, int sum, int index, vector<vector<int>> &res, vector<int> &ans)
{
    if (index >= n)
        return;
    if (sum == 0)
    {
        res.push_back(ans);
        return;
    }
    if (sum < 0)
        return;
    ans.push_back(arr[index]);
    solve(n, arr, sum - arr[index], index, res, ans);
    ans.pop_back();
    solve(n, arr, sum, index + 1, res, ans);
}
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
        int x;
        cin >> x;
        arr.push_back(x);
    }
    int sum;
    cin >> sum;
    // cout << sum;
    vector<vector<int>> res;
    vector<int> ans;
    solve(n, arr, sum, 0, res, ans);
    for (auto x : res)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}