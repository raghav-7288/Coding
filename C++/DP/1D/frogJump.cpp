/*
There is a frog on the '1st' step of an 'N' stairs long staircase.
The frog wants to reach the 'Nth' stair.
'HEIGHT[i]' is the height of the '(i+1)th' stair.If Frog jumps from
'ith' to 'jth' stair, the energy lost in the jump is given by absolute
value of ( HEIGHT[i-1] - HEIGHT[j-1] ). If the Frog is on 'ith' staircase,
he can jump either to '(i+1)th' stair or to '(i+2)th' stair.
Your task is to find the minimum total energy used by the frog to reach from
'1st' stair to 'Nth' stair.
*/
#include <bits/stdc++.h>
using namespace std;
int solve(int pos, int n, vector<int> &heights, vector<int> &dp)
{
    if (pos == n)
        return 0;
    if (dp[pos] != -1)
        return dp[pos];
    int one = INT_MAX, two = INT_MAX;
    if (pos + 1 <= n)
        one = abs(heights[pos] - heights[pos - 1]) + solve(pos + 1, n, heights, dp);
    if (pos + 2 <= n)
        two = abs(heights[pos + 1] - heights[pos - 1]) + solve(pos + 2, n, heights, dp);
    return dp[pos] = min(one, two);
}
/*
From stone 'i', it is possible to reach stones 'i'+1, ‘i’+2… ‘i’+'k'
and the cost incurred will be | Height[i]-Height[j] |,
where 'j' is the landing stone.

int solve(int pos,int n,int k,vector<int> &height,vector<int> &dp){
    if(pos==n) return dp[pos] = 0;
    if(dp[pos]!=-1) return dp[pos];
    int minCost=INT_MAX;
    for(int i=1;i<=k;i++){
        int cost=INT_MAX;
        if(pos+i<=n){
            cost=abs(height[pos-1]-height[pos+i-1])+solve(pos+i,n,k,height,dp);
        }
        minCost=min(minCost,cost);
    }
    return dp[pos]=minCost;
}
*/
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);
    return solve(1, n, heights, dp);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}