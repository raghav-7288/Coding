#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Structure to represent the tree and perform required operations
struct Tree
{
    int N;                   // Number of nodes
    vector<vector<int>> adj; // Adjacency list
    vector<ll> A;            // Values of nodes
    ll K;                    // XOR value
    vector<ll> gain;         // Gain of each node
    ll maxGain;              // Maximum gain achievable

    Tree(int n)
    {
        N = n;
        adj.assign(N + 1, vector<int>()); // 1-based indexing
        A.assign(N + 1, 0LL);
        gain.assign(N + 1, 0LL);
        maxGain = LLONG_MIN;
    }

    // Function to add an undirected edge
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Function to compute gain for each node
    void computeGain()
    {
        for (int i = 1; i <= N; i++)
        {
            gain[i] = (A[i] ^ K) - A[i];
        }
    }

    // Function to perform DFS and find maximum gain
    ll findMaxGain()
    {
        // Initialize maximum gain
        maxGain = LLONG_MIN;

        // Lambda function for DFS
        function<ll(int, int)> dfsMax = [&](int node, int parent) -> ll
        {
            ll currentSum = gain[node];
            for (auto &child : adj[node])
            {
                if (child != parent)
                {
                    ll childSum = dfsMax(child, node);
                    // Include child subtree only if it increases the gain
                    if (childSum > 0)
                    {
                        currentSum += childSum;
                    }
                }
            }
            // Update global maximum gain
            maxGain = max(maxGain, currentSum);
            return currentSum;
        };

        // Start DFS from root node 1
        dfsMax(1, -1);
        return maxGain;
    }

    // Function to compute the maximum possible sum
    ll getMaxSum()
    {
        computeGain();
        ll totalSum = 0;
        for (int i = 1; i <= N; i++)
        {
            totalSum += A[i];
        }
        ll maxGainValue = findMaxGain();
        if (maxGainValue > 0)
        {
            return totalSum + maxGainValue;
        }
        else
        {
            return totalSum;
        }
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Read number of nodes
    int N;
    cin >> N;
    Tree tree(N);

    // Read N-1 edges
    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        tree.addEdge(u, v);
    }

    // Read A[1..N]
    for (int i = 1; i <= N; i++)
    {
        cin >> tree.A[i];
    }

    // Read K
    cin >> tree.K;

    // Compute and print the maximum sum
    ll result = tree.getMaxSum();
    cout << result << "\n";

    return 0;
}
