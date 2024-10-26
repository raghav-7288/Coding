#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool is_possible(int t, const string &S1, const string &S2, const vector<int> &P, const vector<int> &time_i)
{
    int N = S1.length();
    int M = S2.length();
    if (t < N)
        return false;

    int j = 0;

    for (int i = 1; i <= M && j < N; ++i)
    {
        if (time_i[i] <= t && S2[i - 1] == S1[j])
        {
            j++;
        }
    }

    return (j == N);
}

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
        int N, M;
        cin >> N >> M;

        string S1, S2;
        cin >> S1 >> S2;

        vector<int> P(M);
        for (int i = 0; i < M; ++i)
        {
            cin >> P[i];
        }
        vector<int> time_i(M + 1, M + 1);
        for (int j = 1; j <= M; ++j)
        {
            int pos = P[j - 1];
            time_i[pos] = j;
        }

        if (N == 0)
        {
            cout << "1\n";
            continue;
        }
        if (N > M)
        {
            cout << "-1\n";
            continue;
        }
        int left = 1, right = M, answer = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (is_possible(mid, S1, S2, P, time_i))
            {
                answer = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        cout << (answer != -1 ? to_string(answer) : "-1") << "\n";
    }
}
