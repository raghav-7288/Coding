#include <bits/stdc++.h>
using namespace std;
int solve(int i, int n0, int n1, vector<int> &a0, vector<int> &a1, map<int, vector<int>> &mp, int arr, vector<vector<int>> &dp)
{
    if (arr == 0 && i == n0)
        return 0;
    if (arr == 1 && i == n1)
        return 0;
    if (dp[i][arr] != -1)
        return dp[i][arr];

    int val;
    if (arr == 0)
        val = a0[i];
    else
        val = a1[i];

    int canSwitch = (arr == 0) ? (mp.find(a0[i]) != mp.end() ? 1 : 0) : (mp.find(a1[i]) != mp.end() ? 1 : 0);

    if (canSwitch)
    {
        int newi = (arr == 1) ? mp[a1[i]][0] : mp[a0[i]][1];
        int s = solve(newi + 1, n0, n1, a0, a1, mp, !arr, dp);
        int ns = solve(i + 1, n0, n1, a0, a1, mp, arr, dp);
        return dp[i][arr] = val + max(s, ns);
    }
    return dp[i][arr] = val + solve(i + 1, n0, n1, a0, a1, mp, arr, dp);
}
int maxPathSum(vector<int> &a0, vector<int> &a1)
{
    int n0 = a0.size(), n1 = a1.size();
    map<int, vector<int>> mp;
    for (int i = 0; i < n0; i++)
    {
        if (mp.find(a0[i]) == mp.end())
            mp[a0[i]] = {i};
        else
            mp[a0[i]].push_back(i);
    }

    for (int i = 0; i < n1; i++)
    {
        if (mp.find(a1[i]) == mp.end())
            mp[a1[i]] = {i};
        else
            mp[a1[i]].push_back(i);
    }
    map<int, vector<int>> mp2;
    for (auto m : mp)
    {
        if (m.second.size() == 2)
        {
            mp2.insert({m});
        }
    }
    int row = max(n0, n1);
    vector<vector<int>> dp(row, vector<int>(2, -1));

    return max(solve(0, n0, n1, a0, a1, mp2, 0, dp), solve(0, n0, n1, a0, a1, mp2, 1, dp));
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n0, n1;
    cin >> n0 >> n1;
    vector<int> a0(n0), a1(n1);
    for (int i = 0; i < n0; i++)
    {
        cin >> a0[i];
    }
    for (int i = 0; i < n1; i++)
    {
        cin >> a1[i];
    }
    cout << maxPathSum(a0, a1);
    return 0;
}
/*
84 47
25 32 72 110 118 131 147 152 200 206 216 218 224 242 247 250 254 257 265 287 307 324 325 327 334 339 363 377 389 393 402 406 414 417 425 441 442 446 456 463 464 470 473 489 490 495 496 503 510 530 554 557 558 573 592 595 598 614 624 626 629 633 646 666 672 691 697 705 708 755 803 823 852 870 892 893 898 926 927 928 942 946 966 984
18 31 81 95 102 143 152 193 201 246 256 270 318 329 334 339 363 386 405 411 425 462 475 478 486 487 490 516 530 544 550 556 574 628 641 676 684 685 743 791 792 862 897 907 948 967 982
correct 41706
*/