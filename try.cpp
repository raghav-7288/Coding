#include <bits/stdc++.h>
using namespace std;
int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    // #endif

    vector<int> a = {1, 2, 3, 4};
    cout << lower_bound(a.begin(), a.end(), 0) - a.begin();

    return 0;
}