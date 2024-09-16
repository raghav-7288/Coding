#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key, height;
    Node *left, *right;
    Node(int k)
    {
        key = k;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};
class AVL
{
public:
    Node *root = NULL;
    int getHeight(Node *node)
    {
        if (!node)
        {
            return 0;
        }
        return node->height;
    }
    int getBalanceFact(Node *node)
    {
        if (!node)
        {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }
    void inorder(Node *root)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
    void printInorder()
    {
        inorder(root);
        cout << endl;
    }
    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *z = y->left;
        y->left = x;
        x->right = z;
        x->height = getHeight(x->left) + getHeight(x->right) + 1;
        y->height = getHeight(y->left) + getHeight(y->right) + 1;
        return y;
    }
    Node *rightRotate(Node *x)
    {
        Node *y = x->left;
        Node *z = y->right;
        y->right = x;
        x->left = z;
        x->height = getHeight(x->left) + getHeight(x->right) + 1;
        y->height = getHeight(y->left) + getHeight(y->right) + 1;
        return y;
    }
    Node *insert(Node *root, int key)
    {
        if (!root)
        {
            return root = new Node(key);
        }
        if (root->key > key)
        {
            root->left = insert(root->left, key);
        }
        else if (root->key < key)
        {
            root->right = insert(root->right, key);
        }
        else
            return root;

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int bf = getBalanceFact(root);

        if (bf > 1) // L
        {
            if (key < root->left->key) // LL
            {
                return rightRotate(root);
            }
            else if (key > root->left->key) // LR
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        else if (bf < -1) // R
        {
            if (key > root->right->key) // RR
            {
                return leftRotate(root);
            }
            else if (key < root->right->key) // RL
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }
        return root;
    }
    Node *pred(Node *root)
    {
        root = root->left;
        while (root && root->right)
        {
            root = root->right;
        }
        return root;
    }
    Node *succ(Node *root)
    {
        root = root->right;
        while (root && root->left)
        {
            root = root->left;
        }
        return root;
    }
    Node *del(Node *root, int key)
    {
        if (!root)
        {
            return NULL;
        }
        if (root->key > key)
        {
            root->left = del(root->left, key);
        }
        else if (root->key < key)
        {
            root->right = del(root->right, key);
        }
        else
        {
            if (!root->left || !root->right)
            {
                Node *temp = root->left ? root->left : root->right;
                if (!temp)
                {
                    temp = root;
                    root = NULL;
                }
                else
                {
                    *root = *temp;
                }
                free(temp);
            }
            else
            {
                // Node *temp = succ(root);
                // root->key = temp->key;
                // root->right = del(root->right, temp->key);

                Node *temp = pred(root);
                root->key = temp->key;
                root->left = del(root->left, temp->key);
            }
        }
        if (!root)
        {
            return root;
        }

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int bf = getBalanceFact(root);

        if (bf > 1)
        {
            if (getBalanceFact(root->left) >= 0)
            {
                // LL case
                return rightRotate(root);
            }
            else
            {
                // LR case
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        else if (bf < -1)
        {
            if (getBalanceFact(root->right) <= 0)
            {
                // RR case
                return leftRotate(root);
            }
            else
            {
                // RL case
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }
        return root;
    }
};
int main()
{
    AVL avl;
    vector<int> arr = {5, 1, 8, 2, 0, 3, 9, 7, 4, 6};
    for (auto a : arr)
    {
        avl.root = avl.insert(avl.root, a);
    }
    avl.printInorder();
    avl.root = avl.del(avl.root, 5);
    avl.printInorder();
    avl.root = avl.del(avl.root, 8);
    avl.printInorder();
    avl.root = avl.del(avl.root, 2);
    avl.printInorder();
    return 0;
}