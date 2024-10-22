#include <bits/stdc++.h>
using namespace std;
#define ll long long
// Mod value for large calculations (Not used in the current code)
ll mod = 1e9 + 7;
int main()
{
    // These lines are for reading input from file and writing output to a file, used for local debugging
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n;
    cin >> n; // Reading the number of moves

    // Direction vectors to move in four directions: up, right, down, left
    vector<int> dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};

    // 3D DP table where dp[k][i][j] represents the probability of being at position (i, j) after k moves
    vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(8, vector<double>(8, 0)));

    // Initialize the final answer matrix where ans[i][j] holds the final result for cell (i, j)
    vector<vector<double>> ans(8, vector<double>(8, 1));

    // Iterate over all starting positions (i, j) on an 8x8 chessboard
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // Reset the dp table for each starting position (i, j)
            for (int k = 0; k <= n; k++)
            {
                for (int i1 = 0; i1 < 8; i1++)
                {
                    for (int j1 = 0; j1 < 8; j1++)
                    {
                        dp[k][i1][j1] = 0; // Reset all probabilities to 0
                    }
                }
            }

            // Set initial probability of starting position (i, j) at step 0 to 1
            dp[0][i][j] = 1;

            // Simulate all moves from 0 to n
            for (int k = 0; k < n; k++)
            {
                for (int i1 = 0; i1 < 8; i1++)
                {
                    for (int j1 = 0; j1 < 8; j1++)
                    {
                        int totalDir = 0; // Count the number of valid directions

                        // Calculate number of valid moves from current position (i1, j1)
                        for (int d = 0; d < 4; d++)
                        {
                            int u = i1 + dr[d], v = j1 + dc[d];
                            if (u >= 0 && u < 8 && v >= 0 && v < 8)
                            {
                                totalDir++; // Increment if valid direction
                            }
                        }

                        // Spread the probability to all valid moves from current position (i1, j1)
                        for (int d = 0; d < 4; d++)
                        {
                            int u = i1 + dr[d], v = j1 + dc[d];
                            if (u >= 0 && u < 8 && v >= 0 && v < 8)
                            {
                                dp[k + 1][u][v] += dp[k][i1][j1] / totalDir; // Distribute probability
                            }
                        }
                    }
                }
            }
            // Update the final answer for all positions after n moves
            for (int i1 = 0; i1 < 8; i1++)
            {
                for (int j1 = 0; j1 < 8; j1++)
                {
                    ans[i1][j1] *= (1 - dp[n][i1][j1]); // Multiply by the probability of NOT being at (i1, j1)
                }
            }
        }
    }
    // Calculate the expected value (sum of all probabilities in ans matrix)
    double expc = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            expc += ans[i][j]; // Sum the remaining probabilities
        }
    }
    // Print the expected value with fixed precision of 6 decimal places
    cout << fixed << setprecision(6) << expc;
    return 0;
}
