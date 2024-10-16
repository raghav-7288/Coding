#include <bits/stdc++.h>
using namespace std;

void dfs1(int node, const vector<vector<int>> &adj, vector<int> &vis, vector<int> &order)
{
    vis[node] = 1;
    for (int neighbor : adj[node])
    {
        if (!vis[neighbor])
            dfs1(neighbor, adj, vis, order);
    }
    order.push_back(node);
}

void dfs2(int node, const vector<vector<int>> &adj_rev, vector<int> &comp_id, int label, vector<int> &component)
{
    comp_id[node] = label;
    component.push_back(node);
    for (int neighbor : adj_rev[node])
    {
        if (comp_id[neighbor] == -1)
            dfs2(neighbor, adj_rev, comp_id, label, component);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    int var_num = m;
    int num_nodes = 2 * var_num; // Each variable and its negation

    vector<vector<int>> adj(num_nodes), adj_rev(num_nodes);

    // Read input and build implication graph
    for (int i = 0; i < n; i++)
    {
        char a1, a2;
        int t1, t2;
        cin >> a1 >> t1 >> a2 >> t2;
        t1--; // Zero-based indexing
        t2--;

        int u = 2 * t1; // Positive literal of t1
        int v = 2 * t2; // Positive literal of t2
        if (a1 == '-')
            u ^= 1; // If negative, flip to negation
        if (a2 == '-')
            v ^= 1;

        int not_u = u ^ 1; // Negation of u
        int not_v = v ^ 1; // Negation of v

        // Add implications: not_u => v, not_v => u
        adj[not_u].push_back(v);
        adj[not_v].push_back(u);
        adj_rev[v].push_back(not_u);
        adj_rev[u].push_back(not_v);
    }

    // First DFS to get order of nodes
    vector<int> vis(num_nodes, 0), order;
    for (int i = 0; i < num_nodes; i++)
    {
        if (!vis[i])
            dfs1(i, adj, vis, order);
    }

    // Second DFS to find strongly connected components
    vector<int> comp_id(num_nodes, -1);
    vector<vector<int>> comps;
    int label = 0;
    for (int i = num_nodes - 1; i >= 0; i--)
    {
        int node = order[i];
        if (comp_id[node] == -1)
        {
            vector<int> component;
            dfs2(node, adj_rev, comp_id, label++, component);
            comps.push_back(component);
        }
    }

    // Initialize variable assignments to -1 (unassigned)
    vector<int> val(num_nodes, -1);

    // Assign values to variables while checking for conflicts
    for (const vector<int> &comp : comps)
    {
        int set_to = 1; // Set all variables in the component to true by default

        // Check if any variables have their negations already set
        for (int v : comp)
        {
            int neg = v ^ 1; // Get the negation of v
            if (val[neg] != -1)
            {
                set_to = !val[neg]; // Assign opposite of negation
                break;
            }
        }

        // Assign values to variables in the component and detect conflicts
        for (int v : comp)
        {
            int neg = v ^ 1;

            // Conflict detection
            if (val[neg] != -1 && val[neg] == set_to)
            {
                // Conflict detected: variable and its negation are assigned the same value
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }

            if (val[v] == -1)
            {
                val[v] = set_to;
            }
            else if (val[v] != set_to)
            {
                // Conflict detected: variable assigned different values
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    // Prepare the actual variable assignments
    vector<int> actual_val(var_num);
    for (int i = 0; i < var_num; i++)
    {
        actual_val[i] = val[2 * i]; // Variable's positive literal
    }

    // Output the result according to the problem's requirements
    for (int i = 0; i < var_num; i++)
    {
        cout << (actual_val[i] ? "+" : "-");
    }
    cout << endl;

    return 0;
}
