#include <bits/stdc++.h>
using namespace std;
bool can_partition(const vector<int> &A, int N, int K, int X)
{
    int count = 1;
    multiset<int> current_subarray;
    for (int num : A)
    {
        bool conflict = false;
        if (!current_subarray.empty())
        {
            auto it = current_subarray.lower_bound(num - (X - 1));
            if (it != current_subarray.end() && *it <= num + (X - 1))
            {
                conflict = true;
            }
        }
        if (conflict)
        {
            count++;
            current_subarray.clear();
            current_subarray.insert(num);
            if (count > K)
            {
                return false;
            }
        }
        else
        {
            current_subarray.insert(num);
        }
    }
    return count <= K;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int &num : A)
    {
        cin >> num;
    }

    if (N == 0)
    {
        cout << 0;
        return 0;
    }
    int min_A = *min_element(A.begin(), A.end());
    int max_A = *max_element(A.begin(), A.end());
    int low = 0;
    int high = max_A - min_A;
    int result = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (can_partition(A, N, K, mid))
        {
            result = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << result;
    return 0;
}

/*

5 3
8 4 2 4 9

ans 4


6 2
4 8 2 6 10 8

ans 2
*/