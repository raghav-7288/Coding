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
    void print(Node *root)
    {
        if (!root)
            return;
        print(root->left);
        cout << root->cnt_open << " " << root->cnt_cls << " " << root->cnt_full << endl;
        ;
        print(root->right);
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
    Node *res(int low, int high, int left, int right, Node *temp)
    {
        if (right < low || high < left || !temp)
        {
            return new Node();
        }
        else if (left <= low && high <= right)
        {
            return temp;
        }
        int mid = (low + high) / 2;
        Node *leftChild = res(low, mid, left, right, temp->left);
        Node *rightChild = res(mid + 1, high, left, right, temp->right);

        Node *ans = new Node();
        int fulls = min(leftChild->cnt_open, rightChild->cnt_cls);

        ans->cnt_full = fulls + leftChild->cnt_full + rightChild->cnt_full;
        ans->cnt_open = leftChild->cnt_open - fulls + rightChild->cnt_open;
        ans->cnt_cls = leftChild->cnt_cls + rightChild->cnt_cls - fulls;

        return ans;
    }
    void query(int low, int high, int left, int right)
    {
        Node *temp = root;
        cout << res(low, high, left, right, temp)->cnt_full * 2 << endl;
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

    // sgt.print(sgt.root);
    cout << endl;
    cout << sgt.root->cnt_full << " " << sgt.root->cnt_open << " " << sgt.root->cnt_cls << endl;
    for (auto q : queries)
    {
        sgt.query(0, s.length() - 1, q[0] - 1, q[1] - 1);
    }
    return 0;
}
/*
())(())(())(
7
1 1
2 3
1 2
1 12
8 12
5 11
2 10

0
0
2
10
4
6
6
*/