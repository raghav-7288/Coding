#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
void print(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data;
}
Node *push(Node *head, int val)
{
    Node *newNode = new Node(val);
    // newNode->data = val;
    // newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
Node *RecPop(Node *head, int start, int pos)
{
    if (start == pos)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    if (start == pos - 1)
    {
        Node *temp = head;
        start--;
        while (start)
        {
            temp = temp->next;
            start--;
        }
        Node *temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
        return head;
    }
    return RecPop(head, start + 1, pos);
}
Node *pop(Node *head, int pos)
{
    if (head == NULL || head->next == NULL)
    {
        // cout << "Empty List";
        return NULL;
    }
    Node *temp1 = head, *temp2 = NULL;
    if (pos == 1)
    {
        head = head->next;
        free(temp1);
        return head;
    }
    while (pos > 1)
    {
        temp2 = temp1;
        temp1 = temp1->next;
        pos--;
    }
    if (temp1->next == NULL)
    {
        temp2->next = NULL;
        free(temp1);
        return head;
    }
    temp2->next = temp1->next;
    free(temp1);
    return head;
}
Node *reverseList(Node *head)
{
    Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        head = push(head, data);
    }
    // head = reverseList(head);
    // Node *t = head;
    // int pos;
    // cin >> pos;
    // head = RecPop(head, 1, 6);
    print(head);
    return 0;
}