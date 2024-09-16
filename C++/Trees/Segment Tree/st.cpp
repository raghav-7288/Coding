#include <bits/stdc++.h>
using namespace std;
void print(vector<int> &arr)
{
    for (auto a : arr)
        cout << a << " ";
    cout << endl;
}
//~O(N) -> no logn bcz all are not going till depth, also not 4N
void build(int index, int low, int high, vector<int> &nums, vector<int> &tree)
{
    if (low == high)
    {
        tree[low] = nums[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * index + 1, low, mid, nums, tree);
    build(2 * index + 2, mid + 1, high, nums, tree);
    tree[index] = min(tree[2 * index + 1], tree[2 * index + 2]);
}
// O(klogn) -> small ranged query (max times no overlap)
// O(klogn) -> large ranged query (max times comp overlap)
// O(klogn) -> middle ranged query
int query(int index, int low, int high, int left, int right, vector<int> &tree)
{
    if (right < low || high < left) // NO OVERLAP
    {
        return INT_MAX;
    }
    else if (low >= left && high <= right) // COMPLETE OVERLAP
    {
        return tree[index];
    }
    else if ((low <= left && left <= high) || (low <= right && right <= high)) // PARTIAL OVERLAP
    {
        int mid = (low + high) / 2;
        int left_range = query(2 * index + 1, low, mid, left, right, tree);
        int right_range = query(2 * index + 2, mid + 1, high, left, right, tree);
        return min(left_range, right_range);
    }
}
// O(logn)
void update(int index, int low, int high, int pos, int val, vector<int> &tree)
{
    if (low == high)
    {
        tree[index] = val;
        return;
    }
    int mid = (low + high) / 2;
    if (pos <= mid)
    {
        update(2 * index + 1, low, mid, pos, val, tree);
    }
    else
    {
        update(2 * index + 2, mid + 1, high, pos, val, tree);
    }
    tree[index] = min(tree[index * 2 + 1], tree[index * 2 + 2]);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> nums(n), tree(4 * n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    build(0, 0, n - 1, nums, tree);

    print(tree);
    return 0;
}