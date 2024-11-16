#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;
int main()
{
    vector<int> arr = {0, 0, 2, 3};
    cout << lower_bound(arr.begin(), arr.end(), 1) - arr.begin();

    return 0;
}