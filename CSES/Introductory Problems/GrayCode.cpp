#include <bits/stdc++.h>
using namespace std;
int n;
void gc(int i)
{
    int b = i & 1, _n = n - 1;
    string s = "";
    while (_n--)
    {
        i = i >> 1;
        s = to_string(b ^ (i & 1)) + s;
        b = i & 1;
    }
    s = to_string(b) + s;
    cout << s << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < (1 << n); i++)
        gc(i);
    return 0;
}