#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, x, y;
    cin >> n >> x >> y;
    int tar_d = (x + y + 1);
    int ans = 0, cur_d = 1, cur_ele = 1, dir = 0;
    bool small = true;
    while (cur_d < tar_d)
    {
        ans += cur_ele;
        cur_d++;
        if (small)
            cur_ele++;
        else
            cur_ele--;
        if (cur_d == n)
        {
            small = false;
        }
        dir = !dir;
    }
    int start_r, start_c;
    if (dir)
    {
        start_r = min(n - 1, cur_d - 1);
        start_c = tar_d - start_r - 1;
        while (start_r != x && start_c != y)
        {
            start_r--;
            start_c++;
            ans++;
        }
    }
    else
    {
        start_c = min(n - 1, cur_d - 1);
        start_r = tar_d - start_c - 1;
        while (start_r != x && start_c != y)
        {
            start_r++;
            start_c--;
            ans++;
        }
    }
    cout << ans + 1;
    return 0;
}