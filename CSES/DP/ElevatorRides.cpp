#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];

    // minRides,totalWeight for this subset
    vector<pair<int, int>> dp(1 << n, {21, 0});

    dp[0] = {1, 0};

    for (int s = 0; s < (1 << n); s++)
    {
        for (int p = 0; p < n; p++)
        {
            if (s & (1 << p)) // if this person is in this ride
            {
                auto [numRides, total_weight] = dp[s ^ (1 << p)];

                if (total_weight + w[p] > x)
                {
                    numRides++;
                    total_weight = min(total_weight, w[p]);
                }
                else
                {
                    total_weight += w[p];
                }

                dp[s] = min(dp[s], {numRides, total_weight});
            }
        }
    }

    cout << dp[(1 << n) - 1].first;
    return 0;
}