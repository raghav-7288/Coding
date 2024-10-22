/*
For each i
 from 1
 to k
, we first find the probability such that the maximum is i
. That would be equal to (ik)n−(i−1k)n
. This is because we first uniformly choose n
 numbers from 1
 to i
 and subtract those cases in which i
 doesn’t occur. Next we multiply it by i
 to find the expected maximum, and add all those.
Taking care of rounding off. See my code for that.
Time complexity is O(nk)
.
*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ld long double
// ll mod = 1e9 + 7;
// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("../input.txt", "r", stdin);
//     freopen("../output.txt", "w", stdout);
// #endif
//     // int n, k;
//     // cin >> n >> k;
//     // ld ans = 0;
//     // for (int i = 1; i <= k; i++)
//     // {
//     //     ld add = 1, sub = 1;
//     //     for (int j = 1; j <= n; j++)
//     //     {
//     //         add *= (ld)i / (ld)k;
//     //         sub *= (ld)(i - 1) / (ld)k;
//     //     }
//     //     ans += i * (add - sub);
//     // }
//     // ans *= 1e6;
//     // ans = llround(ans);
//     // ans /= 1e6;
//     // cout << fixed << setprecision(6) << ans;

//     // ios::sync_with_stdio(0);
//     // cin.tie(0);
//     // cout.tie(0);
//     ll n, k;
//     cin >> n >> k;
//     ld ans = 0;
//     for (int i = 1; i <= k; i++)
//     {
//         ld add = 1, sub = 1;
//         for (int j = 1; j <= n; j++)
//         {
//             add *= (ld)i / (ld)k;
//             sub *= (ld)(i - 1) / (ld)k;
//         }
//         ans += (ld)(i) * (ld)(add - sub);
//     }
//     ans *= 1e6;
//     ans = llround(ans);
//     ans /= 1e6;
//     cout << fixed << setprecision(6) << ans;
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

int N, K;
double ans, a, b;

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= K; i++)
    {
        a = b = 1.0;
        for (int j = 1; j <= N; j++)
        {
            a *= (double)i / K;
            b *= (double)(i - 1) / K;
        }
        ans += (a - b) * i;
    }
    printf("%.6f\n", ans);
}