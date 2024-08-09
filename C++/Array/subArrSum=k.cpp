// best for arrays with only positives >0
// int longestSubarrayWithSumK(vector<int> a, long long k)
// {
//     int r = 0, l = 0;
//     int n = a.size();
//     int s = a[0];
//     int len = 0;
//     while (r < n)
//     {
//         while (l <= r && s > k)
//         {
//             s -= a[l];
//             l++;
//         }
//         if (s == k)
//         {
//             l = max(l, r - l + 1);
//         }
//         r++;
//         if (r < n)
//         {
//             s += a[r];
//         }
//     }
// }
/*
-> generate all subarraay with sum=k
vector<vector<int>> subarraysWithSumK(vector<int> a, long long k)
{
    vector<vector<int>> all;
    map<int, int> mp;
    int n = a.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum == k)
        {
            vector<int> temp(a.begin(), a.begin() + i + 1);
            all.push_back(temp);
        }
        if (mp.find(sum - k) != mp.end())
        {
            vector<int> temp(a.begin() + mp[sum - k]+1, a.begin() + i + 1);
            all.push_back(temp);
        }
        if (mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }
    return all;
}
*/
// for arrays with any kind of elements
#include<bits/stdc++.h>
using namespace std;
int lenOfLongSubarr(int A[],  int N, int K) 
{ 
    map<int,int> mp;
    int i=0,s=0,ans=0;
    while(i<N){
        s+=A[i];
        if(s==K) ans=max(ans,i+1);
        if(mp.find(s-K) != mp.end()){
            ans=max(ans,i-mp[s-K] );
        }
        if(mp.find(s) == mp.end()) mp[s]=i;
        i++;
    }
    return ans;
} 