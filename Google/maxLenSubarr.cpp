#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll get_sum_of_smallest(const multiset<int> &s, int count)
{
    ll sum = 0;
    int cnt = 0;
    for (auto it = s.begin(); it != s.end() && cnt < count; ++it, ++cnt)
    {
        sum += *it;
    }
    return sum;
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
        int N, X, Y;
        cin >> N >> X >> Y;
        vector<int> A(N);
        for (auto &x : A)
            cin >> x;

        int left = 0;
        int max_length = 0;
        multiset<int> non_zero_elements;

        for (int right = 0; right < N; ++right)
        {
            if (A[right] != 0)
            {
                non_zero_elements.insert(A[right]);
            }

            int K = non_zero_elements.size();

            int Y_prime = min(Y, K);

            int Type1_count = K - Y_prime;
            ll required_X = 0;
            if (Type1_count > 0)
            {
                required_X = get_sum_of_smallest(non_zero_elements, Type1_count);
            }

            while (required_X > X && left <= right)
            {
                if (A[left] != 0)
                {
                    auto it = non_zero_elements.find(A[left]);
                    if (it != non_zero_elements.end())
                    {
                        non_zero_elements.erase(it);
                    }
                }
                left++;

                K = non_zero_elements.size();
                Y_prime = min(Y, K);
                Type1_count = K - Y_prime;
                required_X = 0;
                if (Type1_count > 0)
                {
                    required_X = get_sum_of_smallest(non_zero_elements, Type1_count);
                }
            }

            max_length = max(max_length, right - left + 1);
        }
        cout << max_length << "\n";
    }
}
