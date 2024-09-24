/*
give no. of heads from l-r
flip coins from l-r
heads->1
tails->0
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data, lazy;
    Node *left, *right;
    Node(int d = 0)
    {
        data = d;
        lazy = 0;
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
            if (arr[low])
            {
                return new Node(1);
            }
            return new Node();
        }
        int mid = (low + high) / 2;
        Node *node = new Node();

        node->left = _build(low, mid);
        node->right = _build(mid + 1, high);
        node->data = node->left->data + node->right->data;

        return node;
    }
    void build()
    {
        root = _build(0, arr.size() - 1);
    }
    void _update(int low, int high, int left, int right, Node *temp)
    {
        if (temp->lazy)
        {
            temp->data = (high - low + 1) - temp->data;
            if (low != high)
            {
                temp->left->lazy ^= 1;
                temp->right->lazy ^= 1;
            }
            temp->lazy = 0;
        }

        if (right < low || high < left)
        {
            return;
        }
        else if (left <= low && high <= right)
        {
            temp->data = (high - low + 1) - temp->data;
            if (low != high)
            {
                temp->left->lazy ^= 1;
                temp->right->lazy ^= 1;
            }
            return;
        }
        int mid = (low + high) / 2;
        _update(low, mid, left, right, temp->left);
        _update(mid + 1, high, left, right, temp->right);

        temp->data = temp->left->data + temp->right->data;
    }
    void update(int l, int r)
    {
        Node *temp = root;
        _update(0, arr.size() - 1, l, r, temp);
    }
    int _query(int low, int high, int left, int right, Node *temp)
    {
        if (temp->lazy)
        {
            temp->data = (high - low + 1) - temp->data;
            if (low != high)
            {
                temp->left->lazy ^= 1;
                temp->right->lazy ^= 1;
            }
            temp->lazy = 0;
        }
        if (right < low || high < left)
        {
            return 0;
        }
        else if (left <= low && high <= right)
        {
            return temp->data;
        }
        int mid = (low + high) / 2;
        return _query(low, mid, left, right, temp->left) + _query(mid + 1, high, left, right, temp->right);
    }
    void query(int l, int r)
    {
        Node *temp = root;
        cout << _query(0, arr.size() - 1, l, r, temp) << endl;
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
    for (int i = 0; i < nq; i++)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
        {
            sgt.update(l, r);
        }
        else
        {
            sgt.query(l, r);
        }
    }
    return 0;
}

/*
10
0 1 0 1 0 1 0 1 0 1
5
2 3 6
1 3 7
2 3 6
1 5 9
2 5 8

2
2
3
*/