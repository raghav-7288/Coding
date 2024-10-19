#include <bits/stdc++.h>
using namespace std;

// Function to compute the cost for one side
long long compute_cost(deque<int> &size0, deque<int> &size1, int C)
{
    long long cost = 0;

    // Pair size0 and size1
    while (!size0.empty() && !size1.empty())
    {
        int d0 = size0.front();
        int d1 = size1.front();
        cost += 2LL * max((long long)d0, (long long)d1);
        size0.pop_front();
        size1.pop_front();
    }

    // Handle remaining size0
    while (size0.size() >= 2)
    {
        int d_far = size0.front();
        int d_next = size0[1];
        if ((long long)C < 2LL * (long long)d_next)
        {
            cost += 2LL * (long long)d_far + (long long)C;
            size0.pop_front();
            size0.pop_front();
        }
        else
        {
            break;
        }
    }

    // Carry remaining size0 individually
    while (!size0.empty())
    {
        cost += 2LL * (long long)size0.front();
        size0.pop_front();
    }

    // Handle remaining size1
    while (size1.size() >= 2)
    {
        int d_far = size1.front();
        int d_next = size1[1];
        if ((long long)C < 2LL * (long long)d_next)
        {
            cost += 2LL * (long long)d_far + (long long)C;
            size1.pop_front();
            size1.pop_front();
        }
        else
        {
            break;
        }
    }

    // Carry remaining size1 individually
    while (!size1.empty())
    {
        cost += 2LL * (long long)size1.front();
        size1.pop_front();
    }

    return cost;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int N, C;
        cin >> N >> C;
        // Vectors to store distances
        vector<int> left_size0, left_size1, right_size0, right_size1;
        for (int i = 0; i < N; i++)
        {
            int Xi, Si;
            cin >> Xi >> Si;
            if (Xi < 0)
            {
                int dist = -Xi;
                if (Si == 0)
                {
                    left_size0.push_back(dist);
                }
                else
                {
                    left_size1.push_back(dist);
                }
            }
            else
            {
                int dist = Xi;
                if (Si == 0)
                {
                    right_size0.push_back(dist);
                }
                else
                {
                    right_size1.push_back(dist);
                }
            }
        }

        // Sort in decreasing order
        sort(left_size0.begin(), left_size0.end(), greater<int>());
        sort(left_size1.begin(), left_size1.end(), greater<int>());
        sort(right_size0.begin(), right_size0.end(), greater<int>());
        sort(right_size1.begin(), right_size1.end(), greater<int>());

        // Convert to deque for efficient popping from front
        deque<int> dq_left_size0(left_size0.begin(), left_size0.end());
        deque<int> dq_left_size1(left_size1.begin(), left_size1.end());
        deque<int> dq_right_size0(right_size0.begin(), right_size0.end());
        deque<int> dq_right_size1(right_size1.begin(), right_size1.end());

        // Compute cost for left and right
        long long cost_left = compute_cost(dq_left_size0, dq_left_size1, C);
        long long cost_right = compute_cost(dq_right_size0, dq_right_size1, C);

        long long total_cost = cost_left + cost_right;
        cout << total_cost << "\n";
    }
}