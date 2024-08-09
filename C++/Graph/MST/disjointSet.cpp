#include <bits/stdc++.h>
using namespace std;
class disjointSet
{
private:
    vector<int> parent; // for parent or ultimate parent
    vector<int> rank;
    vector<int> size; // size of current component

public:
    disjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i; // initially parent of i is i
            size[i] = 1;   // initially size of i is 1
        }
    }
    // if same ultimate parent then belong to same component
    int findPar(int node) // return ultimate parent
    {
        if (parent[node] == node)
        {
            return node;
        }
        // Path compression
        return parent[node] = findPar(parent[node]);
    }
    // join the edges in the component
    void unionByRank(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v) // if alredy connect i.e. have same ultimate parent
        {
            return;
        }
        // attach smaller compo to bigger
        // rank wont change if attaching smaller compo to bigger
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
            rank[ulp_v]++; // rank change
            // OR
            // parent[ulp_v]=ulp_u;
            // rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v) // if alredy connect i.e. have same ultimate parent
        {
            return;
        }
        // attach smaller compo to bigger
        // size of child get added to size of parent
        if (size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else // case for smaller or equal
        // for equal size connect any to any
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    disjointSet ds(6);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    if (ds.findPar(1) == ds.findPar(4))
    {
        cout << "SAME\n";
    }
    else
    {
        cout << "NOT SAME\n";
    }
    ds.unionBySize(3, 5);
    if (ds.findPar(1) == ds.findPar(4))
    {
        cout << "SAME\n";
    }
    else
    {
        cout << "NOT SAME\n";
    }

    return 0;
}