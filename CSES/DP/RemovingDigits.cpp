#include <bits/stdc++.h>
using namespace std;
int solve(int n, vector<int> &dp)
{
    if (n <= 0)
        return n == 0 ? 0 : INT_MAX;
    if (dp[n] != -1)
        return dp[n];
    int ans = INT_MAX;
    int temp = n;
    while (temp > 0)
    {
        int digit = temp % 10;
        temp /= 10;
        if (digit == 0)
            continue;
        ans = min(ans, 1 + solve(n - digit, dp));
    }
    return dp[n] = ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << solve(n, dp);
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    if(n == 0){
        cout << "0";
        return 0;
    }
    unordered_map<int, int> mp;
    queue<pair<int, int>> que;
    que.push({n, 0});
    mp[n] = 1;
    while(!que.empty())
    {
        int num = que.front().first;
        int temp = num;
        // cout << temp << endl;
        int d = que.front().second;
        que.pop();
        while(num)
        {
            int digit = num%10;
            num = num / 10;
            if(digit != 0)
            {
                int t = temp - digit;
                if(t == 0){
                    cout << d + 1;
                    return 0;
                }
                else
                {
                    if(mp.find(t) == mp.end()){
                        que.push({t, d+1});
                        mp[t] = 1;
                    }
                }
            }
        }

    }
    return 0;
}
*/