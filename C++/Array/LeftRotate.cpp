// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("../input.txt", "r", stdin);
//     freopen("../output.txt", "w", stdout);
// #endif

//     int n;
//     cin >> n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     int d;
//     cin >> d;
//     d %= n;
//     for (int i = 0; i < d; i++)
//     {
//         int temp = a[0];
//         for (int j = 1; j < n; j++)
//         {
//             a[j - 1] = a[j];
//         }
//         a[n - 1] = temp;
//     }
//     for (auto x : a)
//     {
//         cout << x << " ";
//     }

//     return 0;
// }

// optimal

#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int d;
    cin >> d;
    // to right rotate
    // d = n - d;
    d %= n;
    // reverse(a,b) range-> [a,b)
    reverse(a, a + d);
    reverse(a + d, a + n);
    reverse(a, a + n);
    for (auto x : a)
    {
        cout << x << " ";
    }

    return 0;
}