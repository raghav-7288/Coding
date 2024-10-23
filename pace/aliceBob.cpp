#include <bits/stdc++.h>
using namespace std;

struct State
{
    int x, y, collected, steps;
};

int bfs(vector<vector<int>> &maze, int n, int m, pair<int, int> bobPos, pair<int, int> alicePos)
{
    int totalCoins = 0;
    vector<pair<int, int>> coins;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (maze[i][j] == 2)
            {
                coins.push_back({i, j});
                totalCoins++;
            }
        }
    }

    int fullMask = (1 << totalCoins) - 1; // Full mask when all coins are collected
    queue<State> q;
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(1 << totalCoins, false)));
    map<tuple<int, int, int>, tuple<int, int, int>> parent; // To store parent states for path reconstruction

    // Initialize BFS with Bob's starting position
    q.push({bobPos.first, bobPos.second, 0, 0}); // {x, y, collected, steps}
    visited[bobPos.first][bobPos.second][0] = true;

    // Directions for moving up, down, left, and right
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // BFS
    while (!q.empty())
    {
        auto [x, y, collected, steps] = q.front();
        q.pop();

        // If we reached Alice's position with all coins
        if (x == alicePos.first && y == alicePos.second && collected == fullMask)
        {
            // Reconstruct the path
            vector<pair<int, int>> path;
            tuple<int, int, int> current = {x, y, collected};

            while (parent.find(current) != parent.end())
            {
                path.push_back({get<0>(current), get<1>(current)});
                current = parent[current];
            }

            path.push_back(bobPos); // Add the starting position
            reverse(path.begin(), path.end());

            cout << "Shortest path:" << endl;
            for (auto pos : path)
            {
                cout << "(" << pos.first << ", " << pos.second << ") \n ";
            }
            cout << "END" << endl;
            return steps;
        }

        // Explore the 4 directions
        for (int i = 0; i < 4; ++i)
        {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];

            // Check boundaries and if cell is not blocked
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && maze[newX][newY] != 1)
            {
                int newCollected = collected;

                // If there's a coin in the new position, update the collected bitmask
                if (maze[newX][newY] == 2)
                {
                    for (int coinIndex = 0; coinIndex < coins.size(); ++coinIndex)
                    {
                        if (coins[coinIndex] == make_pair(newX, newY))
                        {
                            newCollected |= (1 << coinIndex);
                            break;
                        }
                    }
                }

                // If this state has not been visited
                if (!visited[newX][newY][newCollected])
                {
                    visited[newX][newY][newCollected] = true;
                    parent[{newX, newY, newCollected}] = {x, y, collected}; // Store the parent state
                    q.push({newX, newY, newCollected, steps + 1});
                }
            }
        }
    }
    return -1; // If we exhaust the queue without finding a valid path
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    // Example input: maze of size 3x3
    int n = 5;
    int m = 4;
    vector<vector<int>> maze = {
        {0, 0, 0, 2},
        {0, 0, 0, 0},
        {0, 0, 2, 0},
        {0, 0, 0, 0},
        {2, 0, 0, 2}};

    // Bob's and Alice's positions
    pair<int, int> bobPos = {0, 0};
    pair<int, int> alicePos = {0, 1};

    int result = bfs(maze, n, m, bobPos, alicePos);

    if (result != -1)
    {
        cout << "Shortest path to collect all coins and reach Alice: " << result << " steps." << endl;
    }
    else
    {
        cout << "It is impossible to collect all coins and reach Alice." << endl;
    }

    return 0;
}