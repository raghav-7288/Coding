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
//     ll n;
//     cin >> n;
//     ll a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     ld ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             ll k;
//             if (a[j] <= a[i])
//             {
//                 k = (a[j] * (a[j] - 1)) / 2;
//             }
//             else
//             {
//                 k = (a[i] * (a[i] - 1)) / 2 + (a[j] - a[i]) * a[i];
//             }
//             ans += (ld)k / (ld)(a[j] * a[i]);
//         }
//     }
//     cout << fixed << setprecision(6) << ans;

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 101;

int N, r[maxN];
long double ans;

int f(int x)
{
    return x * (x - 1) / 2;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &r[i]);
        for (int j = 0; j < i; j++)
        {
            int tot = (r[j] <= r[i]) ? f(r[j]) : (f(r[i]) + (r[j] - r[i]) * r[i]);
            ans += (long double)tot / (r[i] * r[j]);
        }
    }
    printf("%.6Lf\n", ans);
}