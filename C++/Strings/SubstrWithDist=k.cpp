// No. of substrings with no. of distinct char count=k -->O(n)
#include <bits/stdc++.h>
using namespace std;
int solve(string s, int k)
{
    int n = s.length();
    unordered_map<char, int> mp;
    long long int ans = 0;
    int currDist = 0;
    int release = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp[s[i]] == 0)
        {
            currDist++;
        }
        mp[s[i]]++;
        while (release <= i && currDist > k)
        {
            mp[s[release]]--;
            if (!mp[s[release]])
            {
                currDist--;
            }
            release++;
        }
        if (release <= i)
        {
            ans += (i - release + 1);
        }
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string str;
    int k;
    cin >> str >> k;
    // atmost k dist chars - atmost k-1 dist chars = exactly k dist chars
    cout << solve(str, k) - solve(str, k - 1);
    return 0;
}