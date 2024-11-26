#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include <set>

using namespace std;

struct Edge
{
    int u, v;
    int dist;
};

bool isBipartite(vector<vector<int>> &adj, int n)
{
    vector<int> color(n, -1); // -1: unvisited, 0 and 1: colors
    for (int i = 0; i < n; ++i)
    {
        if (color[i] == -1)
        {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int v : adj[u])
                {
                    if (color[v] == -1)
                    {
                        color[v] = color[u] ^ 1;
                        q.push(v);
                    }
                    else if (color[v] == color[u])
                    {
                        return false; // Not bipartite
                    }
                }
            }
        }
    }
    return true;
}

int findMaximumPartitionFactor(vector<vector<int>> &points)
{
    int n = points.size();
    vector<Edge> edges;
    set<int> distances;

    // Compute all pairwise distances
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            edges.push_back({i, j, dist});
            distances.insert(dist);
        }
    }

    // Convert set to sorted vector
    vector<int> uniqueDistances(distances.begin(), distances.end());
    sort(uniqueDistances.begin(), uniqueDistances.end());

    int left = 0, right = uniqueDistances.size() - 1;
    int max_partition_factor = 0;

    // Binary search over unique distances
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int D = uniqueDistances[mid];

        // Build conflict graph
        vector<vector<int>> adj(n);
        for (const Edge &e : edges)
        {
            if (e.dist < D)
            {
                adj[e.u].push_back(e.v);
                adj[e.v].push_back(e.u);
            }
        }

        // Check if the graph is bipartite
        if (isBipartite(adj, n))
        {
            max_partition_factor = D;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return max_partition_factor;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));

    for (int i = 0; i < n; ++i)
    {
        cin >> points[i][0] >> points[i][1];
    }

    int result = findMaximumPartitionFactor(points);
    cout << result << endl;

    return 0;
}
