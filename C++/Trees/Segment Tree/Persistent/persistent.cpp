#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node *left, *right;
    Node(int v = 0) : val(v), left(NULL), right(NULL) {}
};

class SGT
{
public:
    Node *root = NULL;
    vector<int> arr;
    SGT(vector<int> _arr) : arr(_arr) {}
    Node *_build(int low, int high)
    {
        if (low == high)
        {
            return new Node(arr[low]);
        }
        Node *node = new Node();
        int mid = (low + high) / 2;
        node->left = _build(low, mid);
        node->right = _build(mid + 1, high);
        node->val = node->left->val + node->right->val;
        return node;
    }
    Node *build()
    {
        root = _build(0, arr.size() - 1);
        return root;
    }
    void update(Node *pre, Node *cur, int low, int high, int pos, int val)
    {
        if (low == high)
        {
            cur->val = val;
            return;
        }
        int mid = (low + high) / 2;

        if (pos <= mid)
        {
            cur->left = new Node();
            cur->right = pre->right;
            update(pre->left, cur->left, low, mid, pos, val);
        }
        else
        {
            cur->right = new Node();
            cur->left = pre->left;
            update(pre->right, cur->right, mid + 1, high, pos, val);
        }
        cur->val = cur->left->val + cur->right->val;
    }

    int _query(Node *node, int left, int right, int low, int high)
    {
        if (right < low || high < left)
        {
            return 0;
        }
        if (left <= low && high <= right)
        {
            return node->val;
        }
        int mid = (low + high) / 2;
        return _query(node->left, left, right, low, mid) + _query(node->right, left, right, mid + 1, high);
    }

    void query(Node *root, int l, int r)
    {
        cout << _query(root, l, r, 0, arr.size() - 1) << endl;
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
    vector<Node *> versions;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    SGT sgt(arr);
    versions.push_back(sgt.build());

    cin >> nq;
    for (int i = 0; i < nq; i++)
    {
        int t, l, r;
        cin >> t;
        if (t == 1)
        {
            cin >> l >> r;
            Node *pre = versions.back();
            versions.push_back(new Node());
            sgt.update(pre, versions.back(), 0, n - 1, l, r);
        }
        else
        {
            int v;
            cin >> v >> l >> r;
            sgt.query(versions[v], l, r);
        }
    }
    return 0;
}

/*
version[0] = root;

    // upgrading to version-1
    version[1] = new node(NULL, NULL, 0);
    upgrade(version[0], version[1], 0, n-1, 4, 1);

    // upgrading to version-2
    version[2] = new node(NULL, NULL, 0);
    upgrade(version[1],version[2], 0, n-1, 2, 10);

    cout << "In version 1 , query(0,4) : ";
    cout << query(version[1], 0, n-1, 0, 4) << endl;

    cout << "In version 2 , query(3,4) : ";
    cout << query(version[2], 0, n-1, 3, 4) << endl;

    cout << "In version 0 , query(0,3) : ";
    cout << query(version[0], 0, n-1, 0, 3) << endl;

5
1 2 3 4 5
5
1 4 1
1 2 10
2 1 0 4
2 2 3 4
2 0 0 3

11
5
10
*/