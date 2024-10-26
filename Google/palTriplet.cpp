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
        string S;
        cin >> S;
        int n = S.length();
        vector<int> startAt(n, 0);
        vector<int> endAt(n, 0);

        for (int center = 0; center < n; center++)
        {
            int l = center, r = center;
            while (l >= 0 && r < n && S[l] == S[r])
            {
                startAt[l]++;
                endAt[r]++;
                l--;
                r++;
            }
            l = center;
            r = center + 1;
            while (l >= 0 && r < n && S[l] == S[r])
            {
                startAt[l]++;
                endAt[r]++;
                l--;
                r++;
            }
        }
        vector<long long> prefixEndAt(n, 0);
        prefixEndAt[0] = endAt[0];
        for (int i = 1; i < n; i++)
            prefixEndAt[i] = prefixEndAt[i - 1] + endAt[i];

        vector<long long> suffixStartAt(n, 0);
        suffixStartAt[n - 1] = startAt[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffixStartAt[i] = suffixStartAt[i + 1] + startAt[i];

        ll total_triplets = 0;
        for (int center = 0; center < n; center++)
        {
            int l = center, r = center;
            while (l >= 0 && r < n && S[l] == S[r])
            {
                ll pre = (l - 1 >= 0) ? prefixEndAt[l - 1] : 0;
                ll suf = (r + 1 < n) ? suffixStartAt[r + 1] : 0;
                total_triplets += pre * suf;
                l--;
                r++;
            }
            l = center;
            r = center + 1;
            while (l >= 0 && r < n && S[l] == S[r])
            {
                ll pre = (l - 1 >= 0) ? prefixEndAt[l - 1] : 0;
                ll suf = (r + 1 < n) ? suffixStartAt[r + 1] : 0;
                total_triplets += pre * suf;
                l--;
                r++;
            }
        }
        cout << total_triplets << "\n";
    }
}
