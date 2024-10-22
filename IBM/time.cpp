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
    int h = (s[0] - '0') * 10 + (s[1] - '0');
    int m = (s[3] - '0') * 10 + (s[4] - '0');
    int current_minutes = h * 60 + m;
    vector<int> coincidence_times = {0, 65, 131, 196, 262, 327, 393, 458, 524, 589, 655, 720};
    int time_until_coincide = 0;
    bool found = false;
    for (int t : coincidence_times)
    {
        if (t > current_minutes)
        {
            time_until_coincide = t - current_minutes;
            found = true;
            break;
        }
    }
    if (!found)
    {
        time_until_coincide = 720 - current_minutes;
    }
    cout << time_until_coincide << endl;
    return 0;
}
