#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    map<char, int> mp;
    for (auto c : s)
        mp[c]++;
    char oddChar = '#';
    for (auto m : mp)
    {
        if (m.second & 1)
        {
            if (oddChar == '#')
            {
                oddChar = m.first;
            }
            else
            {
                cout << "NO SOLUTION";
                return 0;
            }
        }
    }
    string _s;
    for (auto m : mp)
    {
        if (m.second & 1)
        {
            int len = m.second - 1;
            if (len)
            {
                string temp(len / 2, m.first);
                _s += temp;
            }
        }
        else
        {
            string temp(m.second / 2, m.first);
            _s += temp;
        }
    }
    string rs = _s;
    reverse(rs.begin(), rs.end());
    if (oddChar != '#')
        _s += oddChar;
    _s += rs;
    cout << _s;
    return 0;
}