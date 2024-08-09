#include <bits/stdc++.h>
using namespace std;
void genAllTopo(int n, vector<int> adj[], vector<int> &indegree,
                vector<int> &vis, vector<int> &currTopo,
                vector<vector<int>> &allTopo)
{
    bool allVisited = true;
    for (int i = 0; i < n; i++)
    {
        if (!indegree[i] && !vis[i])
        {
            vis[i] = 1;
            currTopo.push_back(i);
            for (auto x : adj[i])
            {
                indegree[x]--;
            }
            genAllTopo(n, adj, indegree, vis, currTopo, allTopo);
            vis[i] = 0;
            currTopo.pop_back();
            for (auto x : adj[i])
            {
                indegree[x]++;
            }
            allVisited = false;
        }
    }
    if (allVisited)
    {
        if (currTopo.size() != n)
        {
            cout << "CYCLE EXIST";
            return;
        }
        allTopo.push_back(currTopo);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n = 6;
    // cin >> n;
    vector<int> adj[n];
    adj[5] = {2, 0};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};
    vector<vector<int>> allTopo;
    vector<int> currTopo;
    vector<int> vis(n);
    vector<int> indegree(n);
    for (auto x : adj)
    {
        for (auto y : x)
        {
            indegree[y]++;
        }
    }
    genAllTopo(n, adj, indegree, vis, currTopo, allTopo);
    for (auto x : allTopo)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}