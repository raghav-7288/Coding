//All strings
/*
    void solve(int n, string& str, vector<string>& res){
        if(str.length()==n){
            res.push_back(str);
            return;
        }
        str.push_back('0');
        solve(n,str,res);
        str.pop_back();
        str.push_back('1');
        solve(n,str,res);
        str.pop_back();
    }
    vector<string> generateBinaryStrings(int n){
        vector<string> res;
        string str;
        solve(n,str,res);
        return res;
    }
*/
// -----------------------------------------------------------------------------------------------
// Generate all binary strings of length n
// Having no consecutive 1
#include <bits/stdc++.h>
using namespace std;
void solve(int n, int len, vector<vector<int>> &res, vector<int> &ans, int curr)
{
    if (len == n)
    {
        res.push_back(ans);
        return;
    }
    if (curr == 0)
    {
        ans.push_back(0);
        solve(n, len + 1, res, ans, 0);
        ans.pop_back();
        ans.push_back(1);
        solve(n, len + 1, res, ans, 1);
        ans.pop_back();
    }
    else
    {
        ans.push_back(0);
        solve(n, len + 1, res, ans, 0);
        ans.pop_back();
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<int>> res;
    vector<int> ans;
    solve(n, 0, res, ans, 0);
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