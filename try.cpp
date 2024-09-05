
#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    std::vector<int> m = {1, 2, 3, 4, 5};
    std::vector<int> v;

    std::copy(m.begin(), m.end(), std::back_inserter(v));
    for (auto a : v)
        cout << a << " ";

    // Now v contains {1, 2, 3, 4, 5}

    return 0;
}
