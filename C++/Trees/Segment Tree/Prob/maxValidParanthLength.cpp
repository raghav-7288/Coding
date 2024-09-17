/*
given a sequence of brackets
query : give count of valid brckets in l-r
*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int cnt_open, cnt_cls, cnt_full;
    Node *left, *right;
    Node(int o = 0, int c = 0)
    {
        cnt_open = o;
        cnt_cls = c;
        cnt_full = 0;
        left = NULL;
        right = NULL;
    }
};
class SGT
{
public:
    Node *root;
    SGT()
    {
        root = new Node(0, 0);
    }
    Node *create(int low, int high, string &s)
    {
        if (low == high)
        {
            int co = s[low] == '(' ? 1 : 0;
            int cc = s[low] == ')' ? 1 : 0;
            return new Node(co, cc);
        }

        int mid = (low + high) / 2;
        Node *leftChild = create(low, mid, s);
        Node *rightChild = create(mid + 1, high, s);

        Node *root = new Node();
        int fulls = min(leftChild->cnt_open, rightChild->cnt_cls);

        root->cnt_full = fulls + leftChild->cnt_full + rightChild->cnt_full;
        root->cnt_open = leftChild->cnt_open - fulls + rightChild->cnt_open;
        root->cnt_cls = leftChild->cnt_cls + rightChild->cnt_cls - fulls;

        root->left = leftChild;
        root->right = rightChild;

        return root;
    }
    void build(string &s)
    {
        root = create(0, s.length() - 1, s);
    }
    int query(int low, int high, int left, int right)
    {
        return 0;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    int nq;
    cin >> nq;
    vector<vector<int>> queries(nq);
    for (int i = 0; i < nq; i++)
    {
        int l, r;
        cin >> l >> r;
        queries[i] = {l, r};
    }
    SGT sgt;
    sgt.build(s);
    cout << sgt.root->cnt_full << " " << sgt.root->cnt_open << " " << sgt.root->cnt_cls;
    for (auto q : queries)
    {
        cout << sgt.query(0, s.length() - 1, q[0], q[1]) << endl;
    }
    return 0;
}