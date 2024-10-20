/*
https://www.geeksforgeeks.org/samsung-interview-experience-set-39-campus-r-d-noida/
https://www.careercup.com/page?pid=samsung-interview-questions

A Doctor travels from a division to other division where divisions are connected like a graph(directed graph) and
the edge weights are the probabilities of the doctor going from that division to other connected division but the
doctor stays 10mins at each division now there will be given time and had to find the division in which he will be
staying by that time and is determined by finding division which has high probability.

Input is number of test cases followed by the number of nodes, edges, time after which we need to find the division
in which he will be there, the edges starting point, end point, probability.

Note: If he reaches a point where there are no further nodes then he leaves the lab after 10 mins and the traveling
time is not considered and during that 10min at 10th min he will be in next division, so be careful

2
6 10 40
1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5
6 10 10
1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5

6 0.774000
3 0.700000
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
void dfs(int node, double curProp, int t, vector<pair<int, double>> adj[], vector<double> &totalProb)
{
    if (t <= 0)
    {
        totalProb[node] += curProp;
        return;
    }
    for (auto it : adj[node])
    {
        curProp *= it.second;
        dfs(it.first, curProp, t - 10, adj, totalProb);
        curProp /= it.second;
    }
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
        int n, e, t;
        cin >> n >> e >> t;
        vector<pair<int, double>> adj[n + 1];
        while (e--)
        {
            int u, v;
            double p;
            cin >> u >> v >> p;
            adj[u].push_back({v, p});
        }
        vector<double> totalProb(n + 1);
        dfs(1, 1.0, t, adj, totalProb);
        int node;
        double maxProb = -1;
        for (int i = 1; i <= n; i++)
        {
            if (totalProb[i] > maxProb)
            {
                maxProb = totalProb[i];
                node = i;
            }
        }
        cout << node << " " << maxProb << endl;
    }
    return 0;
}