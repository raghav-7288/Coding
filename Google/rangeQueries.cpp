#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isPossible(const vector<ll> &A, ll N, ll M, ll L, ll X)
{
    ll operations = 0;
    ll current_decrements = 0;
    vector<ll> add(N + 2, 0);
    for (ll i = 0; i < N; ++i)
    {
        current_decrements += add[i];
        ll required = A[i] - X - current_decrements;
        if (required > 0)
        {
            operations += required;
            if (operations > M)
            {
                return false;
            }
            current_decrements += required;
            if (i + L < N)
            {
                add[i + L] -= required;
            }
        }
    }
    return operations <= M;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ll I;
    cin >> I;
    while (I--)
    {
        ll N;
        cin >> N;
        vector<ll> A(N);
        for (auto &x : A)
            cin >> x;
        ll M, L;
        cin >> M >> L;
        ll left = 0, right = *max_element(A.begin(), A.end());
        while (left <= right)
        {
            ll mid = left + (right - left) / 2;
            if (isPossible(A, N, M, L, mid))
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        cout << left << "\n";
    }
}
