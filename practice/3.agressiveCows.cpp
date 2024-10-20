/*
Aggressive Cows
You are given an array consisting of n integers which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
The first line of input contains two space-separated integers n and k.
The second line contains n space-separated integers denoting the position of the stalls.
*/

// int solve(int n, int k, vector<int> &stalls) {
//     sort(stalls.begin(),stalls.end());
//     int l=0,h=stalls.back()-stalls[0];
//     while(l<=h){
//         int m=(l+h)/2, tc=1, prev=0;
//         for(int i=1;i<n;i++){
//             if(stalls[i]-stalls[prev] >= m) {tc++;prev=i;}
//         }
//         if(tc>=k) l=m+1;
//         else h=m-1;
//     }
//     return h;
// }