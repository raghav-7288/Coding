#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    // For debugging: read input from input.txt and write output to output.txt
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    // Step 1: Read input size (number of projects)
    int n;
    cin >> n;

    // Step 2: Use map for coordinate compression
    // compress maps time points (start/end times) to compressed coordinates
    map<int, int> compress;

    // Step 3: Arrays to store the start time, end time, and profit for each project
    vector<int> a(n), b(n), p(n);

    // Step 4: Read all project data and mark time points for compression
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> p[i];
        b[i]++; // We increment b[i] to handle half-open intervals [a, b)

        // Store unique time points in the map for coordinate compression
        compress[a[i]], compress[b[i]];
    }

    // Step 5: Assign compressed indices to time points
    // Each unique time point is mapped to a compressed coordinate
    int coords = 0; // A counter to assign compressed indices
    for (auto &v : compress)
    {
        v.second = coords++; // Assign each time point a unique coordinate in increasing order
    }

    // Step 6: Create an array of projects, where project[i] will store
    // all projects that end at the time corresponding to compressed index i.
    vector<vector<pair<int, int>>> project(coords);

    // Step 7: Map each project to its compressed start and end time
    // Each project is represented as (compressed_start_time, profit)
    for (int i = 0; i < n; i++)
    {
        project[compress[b[i]]].push_back({compress[a[i]], p[i]});
    }

    // Step 8: Dynamic programming (dp) array where dp[i] stores the maximum profit
    // achievable up to the time corresponding to compressed index i.
    vector<long long> dp(coords, 0);

    // Step 9: Fill the dp array
    for (int i = 0; i < coords; i++)
    {
        // Option 1: Do not take any project ending at this time point.
        // Carry over the maximum profit from the previous time point.
        if (i > 0)
        {
            dp[i] = dp[i - 1];
        }

        // Option 2: Take projects ending at this time point.
        // For each project (compressed_start_time, profit) that ends at time i,
        // calculate the new maximum profit by adding the profit of the project
        // to the maximum profit achievable at its start time.
        for (auto p : project[i])
        {
            // Update dp[i] to the maximum profit possible by either:
            // - Not taking this project (keep dp[i] as it is)
            // - Taking this project (dp[p.first] + p.second)
            dp[i] = max(dp[i], dp[p.first] + p.second);
        }
    }

    // Step 10: Output the maximum profit achievable up to the last time point
    cout << dp[coords - 1] << endl;

    return 0;
}
