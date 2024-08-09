#include <bits/stdc++.h>
using namespace std;
void Permute(vector<int> &a, vector<vector<int>> &allPerm, vector<int> &currPerm, vector<int> &picked)
{
    if (currPerm.size() == a.size())
    {
        allPerm.push_back(currPerm);
        return;
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (!picked[i])
        {
            picked[i] = 1;
            currPerm.push_back(a[i]);
            Permute(a, allPerm, currPerm, picked);
            currPerm.pop_back();
            picked[i] = 0;
        }
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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> allPerms;
    vector<int> currPerm;
    vector<int> picked(n, 0);
    Permute(a, allPerms, currPerm, picked);
    for (auto x : allPerms)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}