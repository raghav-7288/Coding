#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string s = "";
    int l = s.length();
    int p = 0;
    int n;
    cin >> n;
    int k, h = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        k = i <= n ? (n - i + 1) : (i - n);
        for (int j = 1; j <= 2 * n; j++)
        {
            if (j <= k)
                cout << s[(h++) % l];
            if (j > k && j <= 2 * n - k)
                cout << " ";
            if (j > 2 * n - k)
                cout << s[(h++) % l];
        }
        cout << endl;
    }

    return 0;
}