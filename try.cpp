#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<pair<int, int>> pq;
    pq.push({1, 2});
    pq.push({1, 4});
    pq.push({1, 3});
    pq.push({2, 2});
    while (!pq.empty())
    {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}