#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;
struct Node
{
    char data;
    int freq;
    Node *left, *right;
    Node(char val, int f)
    {
        left = NULL;
        right = NULL;
        data = val;
        freq = f;
    }
};
struct Compare
{
    bool operator()(Node *l, Node *r)
    {
        return l->freq > r->freq;
    }
};
void printHuffman(Node *top, string code)
{
    if (!top)
        return;
    if (top->data != '#')
    {
        cout << top->data << " : " << code << endl;
    }
    printHuffman(top->left, code + "0");
    printHuffman(top->right, code + "1");
}
void huffman(map<char, int> &freq)
{
    priority_queue<Node *, vector<Node *>, Compare> minHeap;
    for (auto m : freq)
    {
        minHeap.push(new Node(m.first, m.second));
    }
    while (minHeap.size() != 1)
    {
        Node *left = minHeap.top();
        minHeap.pop();
        Node *right = minHeap.top();
        minHeap.pop();
        Node *top = new Node('#', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    printHuffman(minHeap.top(), "");
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    map<char, int> freq;
    freq['a'] = 5;
    freq['b'] = 9;
    freq['c'] = 12;
    freq['d'] = 13;
    freq['e'] = 16;
    freq['f'] = 45;
    huffman(freq);
    return 0;
}