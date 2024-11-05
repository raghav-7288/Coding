#include <bits/stdc++.h>
using namespace std;
void dfs(int u, vector<bool> &visited, vector<vector<int>> &adj)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
            dfs(v, visited, adj);
    }
}
bool isConnected(int n, vector<vector<int>> &adj)
{
    vector<bool> visited(n + 1, false);
    int u = -1;
    for (int i = 1; i <= n; i++)
    {
        if (!adj[i].empty())
        {
            u = i;
            break;
        }
    }
    if (u == -1)
        return true;
    dfs(u, visited, adj);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && !adj[i].empty())
            return false;
    }
    return true;
}

bool hasEulerianCircuit(int n, vector<vector<int>> &adj)
{
    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() % 2 != 0)
            return false;
    }
    return isConnected(n, adj);
}

void findEulerianCircuit(int n, vector<vector<int>> &adj)
{
    vector<vector<int>> _adj = adj;
    stack<int> st;
    vector<int> circuit;
    st.push(1);
    int curr_v = 1;
    while (!st.empty())
    {
        if (!_adj[curr_v].empty())
        {
            st.push(curr_v);
            int next_v = _adj[curr_v].back();
            _adj[curr_v].pop_back();

            auto it = find(_adj[next_v].begin(), _adj[next_v].end(), curr_v);
            if (it != _adj[next_v].end())
                _adj[next_v].erase(it);

            curr_v = next_v;
        }
        else
        {
            circuit.push_back(curr_v);
            curr_v = st.top();
            st.pop();
        }
    }
    reverse(circuit.begin(), circuit.end());
    for (int v : circuit)
        cout << v << " ";
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;

    // this methid giving tle
    
    // vector<vector<int>> adj(n + 1);
    // for (int i = 0; i < m; i++)
    // {
    //     int a, b;
    //     cin >> a >> b;
    //     adj[a].push_back(b);
    //     adj[b].push_back(a);
    // }
    // if (hasEulerianCircuit(n, adj))
    // {
    //     findEulerianCircuit(n, adj);
    // }
    // else
    // {
    //     cout << "IMPOSSIBLE";
    // }

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> deg(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
        deg[a]++;
        deg[b]++;
    }

    bool tour_exists = true;
    for (int i = 1; i <= n; i++)
        if (deg[i] & 1)
            tour_exists = false;

    if (!tour_exists)
    {
        printf("IMPOSSIBLE\n");
        return 0;
    }

    stack<int> st;
    st.push(1);
    vector<int> circuit, used(m + 1);

    while (!st.empty())
    {
        int cur = st.top();
        if (deg[cur])
        {
            int next = adj[cur].back().first;
            int edge = adj[cur].back().second;
            adj[cur].pop_back();
            if (!used[edge])
            {
                deg[cur]--;
                deg[next]--;
                used[edge] = 1;
                st.push(next);
            }
        }
        else
        {
            circuit.push_back(cur);
            st.pop();
        }
    }

    if ((int)circuit.size() != m + 1)
        printf("IMPOSSIBLE\n");
    else
    {
        for (int v : circuit)
            cout << v << " ";
    }
    return 0;
}
