/*
#include <bits/stdc++.h> // Include all standard libraries

using namespace std;

// Constants
const int maxN = 2e5 + 1, logN = 20;

// Global variables
bool vis[maxN];         // Visited array for DFS
int N, Q;               // N: number of nodes, Q: number of queries
int ds[maxN];           // Disjoint set / Union-Find array to track components
int d[maxN];            // Depth array to track depth of nodes
int comp[maxN];         // Component ID array to identify different components
int cyc[maxN];          // Cycle length for each node (if it's part of a cycle)
int p[logN][maxN];      // Parent array for binary lifting
vector<int> cycleSeeds; // List of nodes that start cycles
vector<int> G[maxN];    // Adjacency list representing the graph

// Find function for the disjoint set (Union-Find)
int find(int u)
{
    if (ds[u] < 0)
        return u;        // If u is a root of its component
    ds[u] = find(ds[u]); // Path compression optimization
    return ds[u];
}

// Merge function for the disjoint set (Union-Find)
bool merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false; // They are already in the same component
    if (ds[u] < ds[v])
        swap(u, v); // Union by size, always attach smaller to larger
    ds[v] += ds[u]; // Update the size of the root component
    ds[u] = v;      // Make u a child of v
    return true;
}

// Initializes the binary lifting table (p[i][j]) where p[i][j] stores the 2^i-th ancestor of node j
void init_parents()
{
    for (int i = 1; i < logN; i++)
        for (int j = 1; j <= N; j++)
            p[i][j] = p[i - 1][p[i - 1][j]]; // Move up by 2^i by combining two 2^(i-1) jumps
}

// Function to move up by k levels in the ancestor chain using binary lifting
int travel(int u, int k)
{
    int v = u;
    for (int i = logN - 1; i >= 0; i--) // Loop through all binary bits of k
        if (k & (1 << i))               // Check if the i-th bit is set
            v = p[i][v];                // Move up by 2^i
    return v;
}

// Depth-First Search (DFS) to calculate depth and detect cycles
void dfs(int u, int compID)
{
    vis[u] = true;    // Mark node u as visited
    comp[u] = compID; // Assign the component ID
    for (int v : G[u])
    { // Traverse all children (v) of node u
        if (!vis[v])
        {                    // If v is not visited
            d[v] = d[u] + 1; // Increase depth for v
            dfs(v, compID);  // Recursively perform DFS for v
        }
        else
        {
            cyc[u] = d[u] + 1; // If a cycle is detected
        }
        cyc[u] = max(cyc[u], cyc[v]); // Update cycle length if applicable
    }
}

// Query function to find the distance from node a to node b
int query(int a, int b)
{
    if (a == b)
        return 0; // If the nodes are the same, distance is 0

    // Case 1: Nodes are in different components, no path exists
    if (comp[a] != comp[b])
        return -1;

    // Case 2: Start node a is part of a cycle
    if (cyc[a])
    {
        if (!cyc[b])
            return -1;                          // If b is not part of a cycle, no valid path
        return (d[a] - d[b] + cyc[a]) % cyc[a]; // Cycle-related distance calculation
    }

    // Case 3: Both nodes are in trees (non-cyclic components)
    if (!cyc[b])
    {
        if (d[a] <= d[b])
            return -1; // a should be deeper than b in the tree
        int dist = d[a] - d[b];
        return (travel(a, dist) == b) ? dist : -1; // Check if b is an ancestor of a
    }

    // Case 4: Start node a is in a tree, b is part of a cycle
    int root = a;
    for (int i = logN - 1; i >= 0; i--)
    { // Find the root of the tree
        int par = p[i][root];
        if (!cyc[par])
            root = par;
    }
    root = p[0][root]; // Move to the cycle node

    return (d[a] - d[root]) + query(root, b); // Combine tree distance and cycle distance
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    // Read the number of nodes (N) and queries (Q)
    scanf("%d %d", &N, &Q);

    // Initialize the disjoint set array
    fill(ds + 1, ds + N + 1, -1);

    // Input edges and process the graph
    for (int i = 1, x; i <= N; i++)
    {
        scanf("%d", &x);
        p[0][i] = x;       // Set the parent for each node
        G[x].push_back(i); // Build the adjacency list
        if (!merge(x, i))  // Detect cycles and store seeds
            cycleSeeds.push_back(x);
    }

    // Initialize binary lifting table
    init_parents();

    // Perform DFS to find cycles and assign components
    int compID = 1;
    for (int seed : cycleSeeds)
        dfs(seed, compID++);

    // Answer the queries
    for (int i = 0, a, b; i < Q; i++)
    {
        scanf("%d %d", &a, &b);      // Read the query
        printf("%d\n", query(a, b)); // Output the result
    }
}
*/

#include <bits/stdc++.h>
using namespace std;

// A helper template for debugging multiple variables at once.
// Usage: error(var1, var2, ...)
template <typename... T>
#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << "=" << a << ", "; // Output each variable name and its value
    err(++it, args...);
}

// Define commonly used macros
#define int long long // Use 'int' as 'long long' to avoid overflow issues
#define ff first      // For easy access to pair elements
#define ss second
#define endl '\n' // To print new line efficiently

// Constants
const long long inf = 1LL << 60; // A very large number (~1.5e18)
const int md = 1000000007;       // A large prime modulus

// Arrays for binary lifting and auxiliary information
int succ[21][200005]; // Binary lifting table (succ[i][j] is 2^i-th successor of node j)
int vis[200005];      // Visited array for DFS
int len[200005];      // Stores the depth/length from the starting point to the end of its path

// DFS function to calculate lengths of nodes' paths
void dfs(int s)
{
    if (vis[s])
        return;                   // If node s is already visited, return
    vis[s] = 1;                   // Mark node s as visited
    dfs(succ[0][s]);              // Recursively visit the next node
    len[s] = len[succ[0][s]] + 1; // Compute the length of the path
}

// Function to lift a node x by d steps using binary lifting
int lift(int x, int d)
{
    if (d <= 0)
        return x; // If no lifting is needed, return the current node
    int i = 0;
    while (d > 0)
    {              // Decompose d into powers of 2
        if (d & 1) // If the current bit of d is set, move up by 2^i steps
            x = succ[i][x];
        d >>= 1; // Shift d to the right
        i++;
    }
    return x;
}

// Main logic to solve the problem
void solve()
{
    int n, q;
    cin >> n >> q; // Input number of nodes (n) and queries (q)

    // Read successors of each node (directed graph)
    for (int i = 1; i <= n; i++)
        cin >> succ[0][i]; // succ[0][i] is the 1-step successor of node i

    // Fill the binary lifting table (succ[i][j] represents the 2^i-th successor of node j)
    for (int i = 1; i <= 20; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            succ[i][j] = succ[i - 1][succ[i - 1][j]]; // Calculate the 2^i-th successor
        }
    }

    // Perform DFS to calculate the length of the path for each node
    for (int i = 1; i <= n; i++)
        if (!vis[i]) // If the node is not visited yet
            dfs(i);

    // for (auto it : len)
    //     cout << it << "*";
    // cout << endl;

    // Answering queries
    while (q--)
    {
        int x, y;
        cin >> x >> y; // Query: find distance from node x to node y

        int xx = lift(x, len[x]); // Get the node at the end of the path starting from x (end of the cycle)
        // Case 1: If y is reachable from x in a simple path (x and y in the same path)
        if (lift(x, len[x] - len[y]) == y)
            cout << len[x] - len[y] << endl; // Output the difference in lengths (distance)

        // Case 2: If x is in a cycle and y is reachable after completing the cycle
        else if (lift(xx, len[xx] - len[y]) == y)
            cout << len[x] + len[xx] - len[y] << endl; // Output the sum of lengths

        // Case 3: No valid path from x to y
        else
            cout << -1 << endl; // Output -1 for no path
    }
}

// Main function
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); // Fast IO

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int t = 1; // Number of test cases (for now only one)
    // cin >> t; // Uncomment if multiple test cases are provided

    for (int i = 1; i <= t; i++)
    {
        solve(); // Solve the problem
        cout << '\n';
    }
}
