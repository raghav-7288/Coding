#include <bits/stdc++.h>
using namespace std;
/*
void subString(string s, int len)
{
    // Pick starting point in outer loop
    // and lengths of different strings for
    // a given starting point
    for (int i = 0; i < len; i++)
        for (int len = 1; len <= len-i; len++)
            cout << s.substr(i, len) << endl;
}
*/
vector<string> generateSubstrings(string s, vector<string> &subStrs)
{
    if (s.empty())
    {
        return {};
    }
    for (int i = 0; i < s.length(); i++)
    {
        subStrs.push_back(s.substr(0, i + 1));
    }
    generateSubstrings(s.substr(1), subStrs);
    return subStrs;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string s = "abc";
    vector<string> subStrs;
    for (auto t : generateSubstrings(s, subStrs))
    {
        cout << t << endl;
    }
    return 0;
}
