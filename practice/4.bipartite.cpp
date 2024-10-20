/*
Given a graph print either of the set of the vertices that are colored with the same color. And if the graph
is not bipartite print “-1”. Test cases also included the cases when a graph is not connected.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
bool solve(int i, int c, vector<int> adj[], vector<int> &color)
{
    color[i] = c;
    for (auto it : adj[i])
    {
        if (color[it] == -1)
        {
            if (!solve(it, !c, adj, color))
                return false;
        }
        else if (color[it] == c)
            return false;
    }
    return true;
}
bool isBip(int n, vector<int> adj[], vector<int> &color)
{
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
            if (!solve(i, 0, adj, color))
                return false;
    }
    return true;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> adj[n], color(n, -1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int e;
                cin >> e;
                if (e)
                {
                    adj[i].push_back(j);
                }
            }
        }
        if (isBip(n, adj, color))
        {
            for (auto c : color)
                cout << c << " ";
        }
        else
            cout << -1;
        cout << endl;
    }

    return 0;
}