/*
Here is the plain text of the problem you provided:

---

You are given a tree consisting exactly of **n** vertices. A tree is a connected undirected graph with **n - 1** edges. Each vertex **v** of this tree has a value **a_v** assigned to it.

Let **dist(x, y)** be the distance between the vertices **x** and **y**. The distance between the vertices is the number of edges on the simple path between them.

Let's define the cost of the tree as the following value: firstly, let's fix some vertex of the tree. Let it be **v**. Then the cost of the tree is:

∑ from i=1 to n (dist(i, v) * a_i)

Your task is to calculate the maximum possible cost of the tree if you can choose **v** arbitrarily.

### Input:
- The first line contains one integer **n**, the number of vertices in the tree (1 ≤ n ≤ 2 * 10⁵).
- The second line of the input contains **n** integers **a₁, a₂, ..., aₙ** (1 ≤ aᵢ ≤ 2 * 10⁵), where **aᵢ** is the value of the vertex **i**.
- Each of the next **n - 1** lines describes an edge of the tree. Edge **i** is denoted by two integers **uᵢ** and **vᵢ**, the labels of the vertices it connects (1 ≤ uᵢ, vᵢ ≤ n, uᵢ ≠ vᵢ).

It is guaranteed that the given edges form a tree.

### Output:
- Print one integer — the maximum possible cost of the tree if you can choose any vertex as **v**.

---

Let me know if you need further clarifications or help with solving the problem!
*/

#include <bits/stdc++.h>
using namespace std;
long long dfs1(int node, int parent, int dist, vector<long long> &val, vector<int> adj[], vector<long long> &sum, vector<long long> &subtreeSum)
{
    long long cur = val[node];
    sum[1] += val[node] * dist;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        cur += dfs1(it, node, dist + 1, val, adj, sum, subtreeSum);
    }
    return subtreeSum[node] = cur;
}
void dfs2(int node, int parent, vector<long long> &val, vector<int> adj[], vector<long long> &sum, vector<long long> &subtreeSum)
{
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        sum[it] = sum[node] - 2 * subtreeSum[it] + subtreeSum[1];
        dfs2(it, node, val, adj, sum, subtreeSum);
    }
}
void solve(vector<long long> &val, vector<int> adj[], vector<long long> &sum)
{
    vector<long long> subtreeSum(val.size() + 1);
    dfs1(1, 0, 0, val, adj, sum, subtreeSum);
    dfs2(1, 0, val, adj, sum, subtreeSum);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<long long> val(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }
    vector<int> adj[n + 1];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<long long> sum(n + 1);
    solve(val, adj, sum);
    cout << *max_element(sum.begin(), sum.end());
    return 0;
}