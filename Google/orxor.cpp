#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> A(n);
        for (auto &x : A)
            cin >> x;
        int max_bit = 30;
        ll answer = 0;

        for (int bit = max_bit; bit >= 0; bit--)
        {
            int cnt_set = 0;
            for (auto x : A)
            {
                if (x & (1 << bit))
                    cnt_set++;
            }
            int cnt_unset = n - cnt_set;

            if (cnt_set >= k && cnt_unset >= k)
            {
                // It's possible to set this bit in F(B)
                answer |= (1LL << bit);
            }
        }

        cout << answer << "\n";
    }
}
