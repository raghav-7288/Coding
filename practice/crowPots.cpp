/*
There are N pots. Every pots has some water in it. They may be partially filled.
Every pot is associated with overflow number O which tell how many minimum no. of stones required
for that pot to overflow. The crow know O1 to On(overflow no. for all the pots). Crow wants some K
pots to be overflow. So the task is minimum number of stones he can make K pots overflow in worst case.

Array of overflow no--. {1,...,On}
Number of pots--n
No of pots to overflow-- k

Let say two pots are there with overflow no.s {5,58}, and crow has to overflow one pot(k=1).
So crow will put 5 stones in pot with overflow no.(58), it will not overflow, then he will put in
pot with overflow no.(5), hence the total no. of stones to make overflow one pot is=10.

Example:
Array of overflow no {5,58}
Number of pots 2
No of pots to overflow 1
ans : 10

Array of overflow no {65,69}
Number of pots 2
No of pots to overflow 1
ans : 69
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("../input.txt", "r", stdin);
//     freopen("../output.txt", "w", stdout);
// #endif
//     int n, k, l = INFINITY, h;
//     cin >> n >> k;
//     vector<int> ofn(n), arr;
//     for (auto &o : ofn)
//         cin >> o;
//     sort(ofn.begin(), ofn.end());
//     for (int i = n - 1; i > 0; i--)
//         ofn[i] = max(0, ofn[i] - ofn[i - 1]);
//     int ans = 0;
//     for (int i = 0; i < k; i++)
//     {
//         ans += ofn[i] * (n - i);
//     }
//     cout << ans;
//     return 0;
// }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, k;
    // Read the number of pots and number of pots to overflow
    std::cin >> n >> k;
    std::vector<int> O(n);
    // Read the overflow numbers
    for (int i = 0; i < n; ++i)
    {
        std::cin >> O[i];
    }
    int stones_used = 0;
    int pots_overflowed = 0;
    // Create a copy of overflow numbers
    std::vector<int> thresholds = O;
    // Continue until K pots have overflowed
    while (pots_overflowed < k)
    {
        for (int i = 0; i < n && pots_overflowed < k; ++i)
        {
            if (thresholds[i] > 0)
            {
                stones_used++;
                thresholds[i]--;
                if (thresholds[i] == 0)
                {
                    pots_overflowed++;
                }
            }
        }
    }
    std::cout << stones_used << std::endl;
    return 0;
}