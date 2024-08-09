#include <bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int change_r[] = {0, 1, 0, -1};
    int change_c[] = {1, 0, -1, 0};
    vector<int> ans;
    int p = 0, q = 0, k = 0;
    for (int i = 0; i < m * n; i++)
    {
        ans.push_back(mat[p][q]);
        vis[p][q] = 1;
        int new_p = p + change_r[k];
        int new_q = q + change_c[k];

        if (new_p >= 0 && new_p < n && new_q >= 0 && new_q < m && !vis[new_p][new_q])
        {
            p = new_p;
            q = new_q;
        }
        else
        {
            k = (k + 1) % 4;
            p += change_r[k];
            q += change_c[k];
        }
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (auto x : spiralOrder(a))
    {
        cout << x << " ";
    }

    return 0;
}