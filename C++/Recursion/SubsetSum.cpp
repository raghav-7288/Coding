#include <bits/stdc++.h>
using namespace std;
// backward approach
void solve(int n, vector<int> &arr, int sum, int index, vector<vector<int>> &res, vector<int> &ans)
{
    if (index == n)
    {
        if (sum == 0)
        {
            res.push_back(ans);
        }
        return;
    }
    ans.push_back(arr[index]);
    solve(n, arr, sum - arr[index], index + 1, res, ans);
    ans.pop_back();
    solve(n, arr, sum, index + 1, res, ans);
}
// forward approach
void solve2(int n, vector<int> &arr, int currSum, int index, vector<vector<int>> &res, vector<int> &ans, int target)
{
    if (index == n)
    {
        if (currSum == target)
        {
            res.push_back(ans);
        }
        return;
    }
    ans.push_back(arr[index]);
    solve2(n, arr, currSum + arr[index], index + 1, res, ans, target);
    ans.pop_back();
    solve2(n, arr, currSum, index + 1, res, ans, target);
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
    vector<vector<int>> res;
    vector<int> ans;
    // solve(n, arr, sum, 0, res, ans);
    solve2(n, arr, 0, 0, res, ans, sum);
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