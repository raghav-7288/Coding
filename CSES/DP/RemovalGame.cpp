// #include <bits/stdc++.h>
// using namespace std;

// // long long solve(int i, int j, int c, vector<long long> &points, vector<vector<vector<long long>>> &dp)
// // {
// //     if (i > j)
// //         return 0;
// //     if (dp[i][j][c] != -1)
// //         return dp[i][j][c];
// //     if (!c)
// //         dp[i][j][c] = max(points[i] + solve(i + 1, j, !c, points, dp), points[j] + solve(i, j - 1, !c, points, dp));
// //     else
// //         dp[i][j][c] = min(-points[i] + solve(i + 1, j, !c, points, dp), -points[j] + solve(i, j - 1, !c, points, dp));
// //     return dp[i][j][c];
// // }

// const int maxN = 5000;

// int N, x[maxN + 1];
// long long p[maxN + 1], dp[maxN + 1][maxN + 1];
// bool found[maxN + 1][maxN + 1];

// long long sum(int l, int r)
// {
//     return p[r] - p[l - 1];
// }

// long long solve(int l, int r)
// {
//     if (found[l][r])
//         return dp[l][r];
//     if (l == r)
//         return x[l];
//     found[l][r] = true;
//     return dp[l][r] = max(x[l] + sum(l + 1, r) - solve(l + 1, r), x[r] + sum(l, r - 1) - solve(l, r - 1));
// }

// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("../input.txt", "r", stdin);
//     freopen("../output.txt", "w", stdout);
// #endif
//     // int n;
//     cin >> N;
//     // vector<long long> points(n);
//     for (int i = 1; i <= N; i++)
//     {
//         cin >> x[i];
//         p[i] = p[i - 1] + x[i];
//     }
//     // long long sum = accumulate(points.begin(), points.end(), 0LL);
//     // 1
//     // vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
//     // cout << (solve(0, n - 1, 0, points, dp) + sum) / 2;

//     // 2
//     // vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(n + 1, vector<long long>(2, -1)));
//     // for (int i = 0; i < n; i++)
//     // {
//     //     dp[i][i][0] = points[i];
//     //     dp[i][i][1] = -points[i];
//     // }
//     // for (int i = n - 1; i >= 0; i--)
//     // {
//     //     for (int j = i + 1; j < n; j++)
//     //     {
//     //         dp[i][j][0] = max(points[i] + dp[i + 1][j][1], points[j] + dp[i][j - 1][1]);
//     //         dp[i][j][1] = min(-points[i] + dp[i + 1][j][0], -points[j] + dp[i][j - 1][0]);
//     //     }
//     // }
//     // cout << (dp[0][n - 1][0] + sum) / 2;

//     // 3
//     cout << solve(1, N);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(int i, int j, vector<ll> &arr, vector<vector<ll>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    ll left = arr[i] + min(solve(i + 2, j, arr, dp), solve(i + 1, j - 1, arr, dp));
    ll right = arr[j] + min(solve(i, j - 2, arr, dp), solve(i + 1, j - 1, arr, dp));
    return dp[i][j] = max(left, right);
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int n;
    cin >> n;
    vector<ll> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    cout << solve(0, n - 1, arr, dp);

    return 0;
}