#include <bits/stdc++.h>
#include <climits>
using namespace std;
int solve(int s, int e, int n, int arr[], vector<int> &vis)
{
    if (s == e)
        return 0;
    if (vis[s])
        return 1e9;
    vis[s] = 1;
    int l = solve(((s - arr[s]) % n + n) % n, e, n, arr, vis);
    int r = solve((s + arr[s]) % n, e, n, arr, vis);
    vis[s] = 0;
    return 1 + min(l, r);
}
int ArrayChallenge(int arr[], int n)
{
    int M = INT_MIN, cur;
    for (int i = 0; i < n; i++)
    {
        if (M < arr[i])
        {
            M = arr[i];
            cur = i;
        }
    }
    vector<int> vis(n), _vis(n);
    return 1 + min(solve((cur + arr[cur]) % n, cur, n, arr, vis), solve(((cur - arr[cur]) % n + n) % n, cur, n, arr, _vis));
}

int main()
{
    int n = 3;
    int arr[n] = {0, 5, 2};
    cout << ArrayChallenge(arr, n) << endl;
    return 0;
}
