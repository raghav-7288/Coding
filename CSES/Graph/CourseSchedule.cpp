#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1], inDeg(n + 1), schedule;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        inDeg[u]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!inDeg[i])
            q.push(i);
    }

    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        schedule.push_back(n);
        for (auto it : adj[n])
        {
            inDeg[it]--;
            if (!inDeg[it])
                q.push(it);
        }
    }
    if (schedule.size() != n)
        cout << "IMPOSSIBLE";
    else
    {
        reverse(schedule.begin(), schedule.end());
        for (auto c : schedule)
            cout << c << " ";
    }
    return 0;
}