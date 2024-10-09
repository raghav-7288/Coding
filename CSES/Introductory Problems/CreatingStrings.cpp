#include <bits/stdc++.h>
using namespace std;
void solve(int i, string &s, set<string> &st)
{
    if (i == s.length())
    {
        st.insert(s);
        return;
    }
    for (int j = i; j < s.length(); j++)
    {
        swap(s[i], s[j]);
        solve(i + 1, s, st);
        swap(s[i], s[j]);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    set<string> st;
    solve(0, s, st);
    cout << st.size() << endl;
    for (auto s : st)
        cout << s << endl;
    return 0;
}