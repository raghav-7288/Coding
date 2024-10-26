#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
    vector<unordered_map<ll, int>> suffix_freq(N + 1);
    unordered_map<ll, int> current_suffix;
    for (int i = N - 1; i >= 0; --i)
    {
        current_suffix[A[i]]++;
        suffix_freq[i] = current_suffix;
    }
    unordered_map<ll, int> prefix_freq;
    ll total_count = 0;
    for (int q = 0; q < N; ++q)
    {
        for (int r = q + 1; r < N; ++r)
        {
            for (const auto &pair : prefix_freq)
            {
                ll A_p = pair.first;
                int cnt_p = pair.second;

                if (A[q] != 0 && (A_p * A[r]) % A[q] == 0)
                {
                    ll A_s = (A_p * A[r]) / A[q];
                    if (suffix_freq[r + 1].find(A_s) != suffix_freq[r + 1].end())
                    {
                        total_count += (ll)cnt_p * suffix_freq[r + 1][A_s];
                    }
                }
            }
        }
        prefix_freq[A[q]]++;
    }
    cout << total_count << endl;
    return 0;
}