/*
query : give (max-min) of range l-r
*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int max, min;
    Node *left, *right;
    Node(int M = 0, int m = 0)
    {
        max = M;
        min = m;
        left = NULL;
        right = NULL;
    }
};
class SGT
{
public:
    Node *root = NULL;
    vector<int> arr;
    SGT(vector<int> &_arr)
    {
        root = new Node();
        arr = _arr;
    }
    Node *_build(int low, int high)
    {
        if (low == high)
        {
            return new Node(arr[low], arr[low]);
        }
        Node *node = new Node();

        int mid = (low + high) / 2;
        Node *left_range = _build(low, mid);
        Node *right_range = _build(mid + 1, high);

        node->left = left_range;
        node->right = right_range;

        node->max = max(node->left->max, node->right->max);
        node->min = min(node->left->min, node->right->min);

        return node;
    }
    void build()
    {
        root = _build(0, arr.size() - 1);
    }
    void _update(int low, int high, int pos, int val, Node *temp)
    {
        if (low == high)
        {
            temp->max = val;
            temp->min = val;
            return;
        }
        int mid = (low + high) / 2;
        if (pos <= mid)
        {
            _update(low, mid, pos, val, temp->left);
        }
        else
        {
            _update(mid + 1, high, pos, val, temp->right);
        }
        temp->max = max(temp->left->max, temp->right->max);
        temp->min = min(temp->left->min, temp->right->min);
    }
    void update(int pos, int val)
    {
        Node *temp = root;
        _update(0, arr.size() - 1, pos, val, temp);
    }
    Node *_query(int low, int high, int left, int right, Node *temp)
    {
        if (right < low || high < left)
        {
            return new Node(INT_MIN, INT_MAX);
        }
        else if (left <= low && high <= right)
        {
            return temp;
        }
        int mid = (low + high) / 2;
        Node *left_range = _query(low, mid, left, right, temp->left);
        Node *right_range = _query(mid + 1, high, left, right, temp->right);

        Node *ans = new Node();
        ans->max = max(left_range->max, right_range->max);
        ans->min = min(left_range->min, right_range->min);

        return ans;
    }
    int query(int left, int right)
    {
        Node *temp = root;
        Node *res = _query(0, arr.size() - 1, left, right, temp);
        return res->max - res->min;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, nq;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    SGT sgt(arr);
    sgt.build();
    cin >> nq;
    vector<vector<int>> queries;
    for (int i = 0; i < nq; i++)
    {
        int t, l, r;
        cin >> t >> l >> r;
        queries.push_back({t, l, r});
    }
    for (auto q : queries)
    {
        if (q[0] == 1)
        {
            sgt.update(q[1], q[2]);
        }
        else
            cout << sgt.query(q[1], q[2]) << endl;
    }
    return 0;
}

/*
10
1 2 3 4 5 6 7 8 9 10
5
2 3 6
1 3 7
2 3 6
1 5 9
2 5 8

3
2
2
*/