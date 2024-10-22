/*
    #include <bits/stdc++.h>
    using namespace std;
    const int maxN = 1e6+1;
    int T, lose[42] = { 0, 1, 2, 4, 7, 10, 20, 23, 26, 50, 53, 270, 273, 276, 282, 285, 288, 316, 334, 337, 340, 346, 359, 362, 365, 386, 389, 392, 566, 630, 633, 636, 639, 673, 676, 682, 685, 923, 926, 929, 932, 1222 };
    bool b[maxN];
    void init(){
        for(int x : lose)
            b[x] = true;
    }
    int main(){
        init();
        scanf("%d", &T);
        for(int t = 0, N; t < T; t++){
            scanf("%d", &N);
            printf("%s\n", b[N] ? "second" : "first");
        }
    }
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;
int mex(vector<ll> &vec)
{
    set<ll> st(vec.begin(), vec.end());
    for (int i = 0; i < 1000001; i++)
    {
        if (!st.count(i))
            return i;
    }
    return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ll limit = 2000;
    vector<ll> dp(limit);
    for (int i = 3; i <= limit; i++)
    {
        vector<ll> vec;
        for (int j = 1; 2 * j < i; j++)
        {
            vec.push_back(dp[j] ^ dp[i - j]);
        }
        dp[i] = mex(vec);
    }
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n >= limit)
            cout << "first";
        else if (dp[n] == 0)
            cout << "second";
        else
            cout << "first";
        cout << "\n";
    }
    return 0;
}