#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    priority_queue<pair<pair<int, int>, int>> pq;
    pq.push({{1, 5}, 2});
    pq.push({{3, 4}, 1});
    pq.push({{2, 3}, 5});
    pq.push({{4, 2}, 3});
    pq.push({{5, 1}, 4});
    while (!pq.empty())
    {
        cout << pq.top().first.first << " " << pq.top().first.second << " " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}