#include <bits/stdc++.h>
using namespace std;
/*
STL:
    next_permtation(a.begin(),a.end());
    return a;
    -->a will change to its next permutation
    -->O(n)

    //same for prev_permutation()
*/
void nextPermutation(vector<int> &a)
{
    int n = a.size();
    int breakPoint = -1;
    for (int i = n - 2; i > -1; i--)
    {
        if (a[i] < a[i + 1])
        {
            breakPoint = i;
            break;
        }
    }
    if (breakPoint == -1)
    {
        reverse(a.begin(), a.end());
        return;
    }
    for (int i = n - 1; i > breakPoint; i--)
    {
        if (a[i] > a[breakPoint])
        {
            swap(a[i], a[breakPoint]);
            break;
        }
    }
    reverse(a.begin() + breakPoint + 1, a.end());
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    nextPermutation(a);
    for (auto x : a)
    {
        cout << x << " ";
    }

    return 0;
}