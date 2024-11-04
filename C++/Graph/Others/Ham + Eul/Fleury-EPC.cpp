/*
Following is Fleury’s Algorithm for printing the Eulerian trail or cycle
1.Make sure the graph has either 0 or 2 odd vertices.
2.If there are 0 odd vertices, start anywhere. If there are 2 odd vertices, start at one of them.
3.Follow edges one at a time. If you have a choice between a bridge and a non-bridge, always choose the non-bridge.
4.Stop when you run out of edges.
TC -> O((V+E)^2)
*/

#include <bits/stdc++.h>
using namespace std;
void addEdge(int u, int v, vector<int> adj[])
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void removeEdge(int u, int v, vector<int> adj[])
{
    adj[u].erase(find(adj[u].begin(), adj[u].end(), v));
    adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
}
int dfs(int node, vector<int> &vis, vector<int> adj[])
{
    int cnt = 1;
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            cnt += dfs(it, vis, adj);
        }
    }
    return cnt;
}
bool isBridge(int u, int v, int n, vector<int> adj[])
{
    vector<int> vis(n), vis1(n);
    int countBefore = dfs(u, vis, adj);
    removeEdge(u, v, adj);
    int countAfter = dfs(u, vis1, adj);
    addEdge(u, v, adj);
    return countBefore > countAfter;
}
void getEuler(int node, int n, vector<int> adj[], vector<vector<int>> &edges)
{
    while (!adj[node].empty())
    {
        int it = adj[node][0];
        if (adj[node].size() == 1 || !isBridge(node, it, n, adj)) // iff only this node in adj or this is not bridge
        {
            edges.push_back({node, it});
            removeEdge(node, it, adj);
            getEuler(it, n, adj, edges);
        }
        else
        {
            // push bridge to end
            adj[node].erase(adj[node].begin());
            adj[node].push_back(it);
        }
    }
}

vector<vector<int>> euler(int n, vector<int> adj[])
{
    int oddVertex = 0; // if no odd vertex start from any
    for (int i = 0; i < n; i++)
    {
        if (adj[i].size() & 1)
        {
            oddVertex = i; // start from any one of the two odd verteces
            break;
        }
    }
    vector<vector<int>> edges;
    getEuler(oddVertex, n, adj, edges);
    return edges;
}
int main()
{
    int n = 4;
    vector<int> adj[4];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    for (auto e : euler(n, adj))
    {
        cout << e[0] << "-" << e[1] << endl;
    }
    return 0;
}