#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
int gh(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + max(gh(root->left), gh(root->right));
}
TreeNode *lr(TreeNode *x)
{
    TreeNode *y = x->right, *z = y->left;
    y->left = x;
    x->right = z;
    return y;
}
TreeNode *rr(TreeNode *x)
{
    TreeNode *y = x->left, *z = y->right;
    y->right = x;
    x->left = z;
    return y;
}
TreeNode *insert(TreeNode *root, int x)
{
    if (!root)
        return root = new TreeNode(x);
    else if (root->val > x)
        root->left = insert(root->left, x);
    else if (root->val < x)
        root->right = insert(root->right, x);
    else
        return root;
    int bf = gh(root->left) - gh(root->right);
    if (bf > 1)
    {
        if (x < root->left->val)
            return rr(root);
        else if (x > root->left->val)
        {
            root->left = lr(root->left);
            return rr(root);
        }
    }
    else if (bf < -1)
    {
        if (x > root->right->val)
            return lr(root);
        else if (x < root->right->val)
        {
            root->right = rr(root->right);
            return lr(root);
        }
    }
    return root;
}
TreeNode *sortedListToBST(ListNode *head)
{
    if (!head)
        return NULL;
    ListNode *temp = head;
    TreeNode *root = NULL;
    while (temp)
    {
        root = insert(root, temp->val);
        temp = temp->next;
    }
    return root;
}
void inorder(TreeNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(-1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(-2);
    head->next->next->next->next = new ListNode(-3);
    head->next->next->next->next->next = new ListNode(3);
    TreeNode *root = sortedListToBST(head);
    inorder(root);
    return 0;
}