#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &a, vector<int> &b)
{
    int i = 0, j = 0, ans = 0, n = a.size();
    while (i < n)
    {
        if (a[i] != b[j])
        {
            if (i < n - 1 && a[i + 1] == a[i])
            {
                swap(a[i + 1], b[j]);
                ans += min(a[i + 1], b[j]);
            }
            else if (j < n - 1 && b[j + 1] == b[j])
            {
                swap(a[i], b[j + 1]);
                ans += min(a[i], b[j + 1]);
            }
            else
                return -1;
        }
        i++;
        j++;
    }
    return ans;
}
int main()
{
    vector<int> A = {1, 1, 1, 1, 2, 2, 2, 5}, B = {3, 3, 3, 3, 4, 4, 5, 2};
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    cout << solve(A, B);
    return 0;
}