#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, nq;
    cin >> n >> nq;
    vector<vector<int>> lift(n + 1, vector<int>(31));
    for (int i = 1; i <= n; i++)
    {
        cin >> lift[i][0];
    }
    for (int j = 1; j < 31; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            lift[i][j] = lift[lift[i][j - 1]][j - 1];
        }
    }
    for (int q = 0; q < nq; q++)
    {
        int start, steps;
        cin >> start >> steps;
        for (int i = 0; i < 31; i++)
        {
            if (steps & (1 << i))
            {
                start = lift[start][i];
            }
        }
        cout << start << " ";
    }
    return 0;
}
