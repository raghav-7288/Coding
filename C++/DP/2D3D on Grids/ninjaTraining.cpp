/*
N days
each day one of 3 activities
every activity has a merit point
no same activiy on consecutive day
return max merit
    3 days:
    18 11 19
    4 13 7
    1 8 13
    out-> 45

    2 days:
    10 50 1
    5 100 11
    out-> 110
*/

/*
Tabulation

    int maximumPoints(vector<vector<int>>& arr, int n) {
        vector<vector<int>> dp(n,vector<int>(3,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                if(!i){
                    dp[i][j]=arr[i][j];
                }else{
                    int a=INT_MIN;
                    for(int k=0;k<3;k++){
                        if(k!=j) a=max(a,dp[i-1][k]);
                    }
                    dp[i][j]=a+arr[i][j];
                }
            }
        }
        int ans=INT_MIN;
        for(auto a:dp[n-1]) ans=max(ans,a);
        return ans;
    }
*/
#include <bits/stdc++.h>
using namespace std;
int solve(int day, int prev, int n, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (day >= n)
        return 0;
    if (dp[day][prev] != -1)
        return dp[day][prev];
    int run = INT_MIN, fight = INT_MIN, learn = INT_MIN;
    if (prev != 1)
    {
        run = points[day][0] + solve(day + 1, 1, n, points, dp);
    }
    if (prev != 2)
    {
        fight = points[day][1] + solve(day + 1, 2, n, points, dp);
    }
    if (prev != 3)
    {
        learn = points[day][2] + solve(day + 1, 3, n, points, dp);
    }
    return dp[day][prev] = max(run, max(fight, learn));
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(0, 0, n, points, dp);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n = 3;
    vector<vector<int>> points = {{18, 11, 19}, {4, 13, 7}, {1, 8, 13}};
    cout << ninjaTraining(n, points);
    return 0;
}
