#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
};
void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << temp->val;
}
ListNode *push(ListNode *head, int val)
{
    ListNode *newNode = new ListNode();
    newNode->val = val;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
void reverse(ListNode *head)
{
    ListNode *prev = NULL, *curr = head, *next = NULL;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
}
void reverseK(ListNode *head, ListNode *currPrev, ListNode *currHead)
{
    ListNode *prev = currPrev, *curr = head, *next = NULL;
    while (curr != currHead)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (k == 1)
        return head;
    ListNode *temp1 = head, *temp2 = head, *currHead = head, *currPrev = NULL,
             *prevHead = NULL;
    int len = 0;
    while (temp1)
    {
        temp1 = temp1->next;
        len++;
    }
    temp1 = head;
    int noOfRev = len / k;
    bool flag = true;
    while (noOfRev--)
    {
        temp1 = currHead;
        temp2 = currHead;
        int currLen = k;
        currLen--;
        while (currLen--)
        {
            temp2 = temp2->next;
            currHead = currHead->next;
        }
        currHead = currHead->next;
        reverseK(temp1, currHead, prevHead);
        if (flag)
        {
            head = temp2;
            flag = false;
        }
        prevHead = temp1;
    }
    return head;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    ListNode *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        head = push(head, val);
    }
    int k;
    cin >> k;
    head = reverseKGroup(head, k);
    print(head);
    return 0;
}