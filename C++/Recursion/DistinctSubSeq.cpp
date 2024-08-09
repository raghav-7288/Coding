// Count All distinct Subsequences of a string
#include <bits/stdc++.h>
using namespace std;
void solve(string s, string &str, set<string> &SET, int index)
{
    if (index == s.length())
    {
        SET.insert(str);
        cout << "\"" << str << "\"" << endl;
        return;
    }
    str.push_back(s[index]);
    solve(s, str, SET, index + 1);
    str.pop_back();
    solve(s, str, SET, index + 1);
}
int distinctSubsequences(string s)
{
    set<string> SET;
    string str = "";
    solve(s, str, SET, 0);
    return SET.size();
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    cout << distinctSubsequences(s);
    return 0;
}