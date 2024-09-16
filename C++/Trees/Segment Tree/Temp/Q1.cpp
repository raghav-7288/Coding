/*
given 2 arrays and 2 type of queries
1. give min : [ # L1 R1 L2 R2 ]
1. update : [ # # pos val ]
*/
#include <bits/stdc++.h>
using namespace std;
void print(vector<int> &arr)
{
    for (auto a : arr)
        cout << a << " ";
    cout << endl;
}
class SGTmin
{
public:
    vector<int> segTree;
    SGTmin(int n)
    {
        segTree.resize(4 * n);
    }

    void build(int index, int low, int high, vector<int> &a)
    {
        if (low == high)
        {
            segTree[index] = a[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * index + 1, low, mid, a);
        build(2 * index + 2, mid + 1, high, a);
        segTree[index] = min(segTree[2 * index + 1], segTree[2 * index + 2]);
    }
    void update(int index, int low, int high, int p, int v)
    {
        if (low == high)
        {
            segTree[index] = v;
            return;
        }
        int mid = (low + high) / 2;
        if (p <= mid)
        {
            update(2 * index + 1, low, mid, p, v);
        }
        else
        {
            update(2 * index + 2, mid + 1, high, p, v);
        }
        segTree[index] = min(segTree[2 * index + 1], segTree[2 * index + 2]);
    }
    int query(int index, int low, int high, int left, int right)
    {
        if (right < low || high < left)
        {
            return INT_MAX;
        }
        else if (left <= low && high <= right)
        {
            return segTree[index];
        }
        else
        {
            int mid = (low + high) / 2;
            int leftRange = query(2 * index + 1, low, mid, left, right);
            int rightRange = query(2 * index + 2, mid + 1, high, left, right);
            return min(leftRange, rightRange);
        }
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n, mid, nq;
    cin >> n >> mid;
    vector<int> a1(n), a2(mid);
    for (int i = 0; i < n; i++)
    {
        cin >> a1[i];
    }
    for (int i = 0; i < mid; i++)
    {
        cin >> a2[i];
    }
    cin >> nq;
    vector<vector<int>> queries(nq);

    for (int i = 0; i < nq; i++)
    {
        int query_type;
        cin >> query_type;

        if (query_type == 1)
        {
            queries[i] = vector<int>(5);
            queries[i][0] = query_type;
            for (int j = 1; j < 5; j++)
            {
                cin >> queries[i][j];
            }
        }
        else
        {
            queries[i] = vector<int>(4);
            queries[i][0] = query_type;
            for (int j = 1; j < 4; j++)
            {
                cin >> queries[i][j];
            }
        }
    }
    SGTmin sgt1(n), sgt2(mid);
    sgt1.build(0, 0, n - 1, a1);
    sgt2.build(0, 0, mid - 1, a2);

    for (auto q : queries)
    {
        if (q[0] == 1)
        {
            cout << min(sgt1.query(0, 0, n - 1, q[1], q[2]), sgt2.query(0, 0, mid - 1, q[3], q[4])) << endl;
        }
        else
        {
            if (q[1] == 1)
            {
                sgt1.update(0, 0, n - 1, q[2], q[3]);
            }
            else
            {
                sgt2.update(0, 0, mid - 1, q[2], q[3]);
            }
        }
    }
    // print(tree);
    return 0;
}

/*
10 5
5 1 7 2 0 3 8 4 6 9
5 10 15 20 25
4
1 1 5 0 3
2 1 2 -1
2 2 2 -10
1 1 5 0 3

op
0
-10

*/