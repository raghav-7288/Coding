// find max length palindromic substring
// aproach-> from every index expand left and right boundaries if s[l]==s[r]
// check for both odd length and even length palindrome
#include <bits/stdc++.h>
using namespace std;
// Expand Around Center
string solve(int s, int e, string str)
{
    while (s >= 0 && e < str.length() && str[s] == str[e])
    {
        s--;
        e++;
    }
    return str.substr(s + 1, e - s - 1);
}
string longestPalindrome(string s)
{
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        string temp1 = solve(i, i, s);     // odd length
        string temp2 = solve(i, i + 1, s); // even length
        // store max in temp;
        if (temp1.length() > ans.length())
            ans = temp1;
        if (temp2.length() > ans.length())
            ans = temp2;
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}