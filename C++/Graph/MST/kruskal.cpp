#include <bits/stdc++.h>
using namespace std;
class disjointSet
{
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

public:
    disjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findPar(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v)
        {
            return;
        }
        if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else
        {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v)
        {
            return;
        }
        if (size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};
bool basedOnwt(vector<int> edge1, vector<int> edge2)
{
    return edge1[2] < edge2[2];
}
int kruskal(vector<vector<int>> edges, int n)
{
    // if adj given convert to edges;
    // vector<vector<int>> adj[]
    // vector<vector<int>> edges;
    // for(int i=0;i<V;i++){
    //     for(auto x:adj[i]){
    //         edges.push_back({i,x[0],x[1]});
    //     }
    // }
    disjointSet ds(n);
    int mstWt = 0;
    // sort edges based on weight;
    sort(edges.begin(), edges.end(), basedOnwt);
    for (auto x : edges)
    {
        int from = x[0];
        int to = x[1];
        int ew = x[2];
        if (ds.findPar(from) != ds.findPar(to))
        {
            mstWt += ew;
            ds.unionByRank(from, to);
        }
    }
    return mstWt;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int e, n;
    cin >> e >> n;
    vector<vector<int>> edges;
    while (e--)
    {
        int from, to, wt;
        cin >> from >> to >> wt;
        edges.push_back({from, to, wt});
    }
    // cout << prims(edges, n, 0);
    cout << kruskal(edges, n);
    return 0;
}