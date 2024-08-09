#include <bits/stdc++.h>
using namespace std;
void dnf(vector<int> &v)
{
    int l = 0, m = 0, h = v.size() - 1;
    while (m <= h)
    {
        switch (v[m])
        {
        case 0:
            swap(v[l], v[m]);
            l++;
            m++;
            break;
        case 1:
            m++;
            break;
        case 2:
            swap(v[m], v[h]);
            h--;
            break;
        }
    }
}
int main()
{
    vector<int> v = {0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2};
    dnf(v);
    for (auto x : v)
    {
        cout << x << " ";
    }
    return 0;
}
