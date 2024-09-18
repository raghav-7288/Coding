/*
given a sequence of brackets
query : give count of valid brckets in l-r
*/
#include <bits/stdc++.h>
using namespace std;
class SGT
{
public:
    vector<int> tree;
    SGT(int n)
    {
        tree.resize(4 * n);
    }
    void build(int index, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            tree[index] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * index + 1, low, mid, arr);
        build(2 * index + 2, mid + 1, high, arr);
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }
    void update(int index, int low, int high, int pos, int val)
    {
        if (low == high)
        {
            tree[index] -= val;
            return;
        }
        int mid = (low + high) / 2;
        if (pos <= mid)
        {
            update(2 * index + 1, low, mid, pos, val);
        }
        else
        {
            update(2 * index + 2, mid + 1, high, pos, val);
        }
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }
    int query(int index, int low, int high, int left, int right)
    {
        if (right < low || high < left)
        {
            return 0;
        }
        else if (left <= low && high <= right)
        {
            return tree[index];
        }
        int mid = (low + high) / 2;
        return query(2 * index + 1, low, mid, left, right) + query(2 * index + 2, mid + 1, high, left, right);
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, maxi = -1, ans = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxi = max(maxi, arr[i]);
    }
    vector<int> freq(maxi + 1);
    for (auto a : arr)
    {
        freq[a]++;
    }
    SGT sgt(maxi + 1);
    sgt.build(0, 0, maxi, freq);
    for (int i = 0; i < n; i++)
    {
        sgt.update(0, 0, maxi, arr[i], 1);
        ans += sgt.query(0, 0, maxi, 1, arr[i] - 1);
    }
    cout << ans;
    return 0;
}
/*
6
6 4 5 3 1 2

13
*/