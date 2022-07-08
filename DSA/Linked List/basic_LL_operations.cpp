#include <bits/stdc++.h>
using namespace std;
#define ll long long

// linked list blueprint/structure
class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};
int length(node *head)
{
    int l = 0;
    while (head != NULL)
    {
        l++;
        head = head->next;
    }
    return l;
}
void insert_head(node *&head, int d)
{

    node *temp = head;
    head = new node(d);
    head->next = temp;
}
void insert_at_tail(node *&head, int d)
{
    if (head == NULL)
        insert_head(head, d);
    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = new node(d);
}
void insert_at_middle(node *&head, int d, int p)
{
    if (head == NULL || p == 0)
    {
        insert_head(head, d);
        return;
    }
    int len = length(head);
    if (p > len)
    {
        insert_at_tail(head, d);
        return;
    }
    int jump = 1;
    node *ptr = head;
    while (jump <= p - 1)

    {
        ptr = ptr->next;
        jump++;
    }
    node *temp = new node(d);
    temp->next = ptr->next;
    ptr->next = temp;
}
void delete_head(node *&head)
{
    if (head == NULL)
        return;
    node *temp = head;
    head = head->next;
    delete temp;
}
void delete_tail(node *&head)
{
    if (head == NULL)
        return;
    if (length(head) == 1)
    {
        delete_head(head);
        return;
    }
    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete (temp->next);

    temp->next = NULL;
}
void delete_middle(node *&head, int p)
{
    if (head == NULL)
        return;
    if (p > length(head))
    {
        delete_tail(head);
        return;
    }
    int jump = 1;
    node *ptr = head;
    while (jump <= p - 1)
    {
        ptr = ptr->next;
        jump++;
    }
    node *temp = ptr->next;
    ptr->next = temp->next;
    delete temp;
}
bool search(node *head, int key)
{
    while (head != NULL)
    {
        if (head->data == key)
            return true;
        head = head->next;
    }
    return false;
}
bool search_recursive(node *head, int key)
{
    if (head == NULL)
        return false;
    if (head->data == key)
        return true;
    return search_recursive(head->next, key);
}
void print_ll(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}
void take_input(node *&head)
{
    int d;
    cin >> d;
    while (d != -1)
    {
        insert_head(head, d);
        cin >> d;
    }
}
ostream &operator<<(ostream &os, node *head)
{
    print_ll(head);
    return os;
}
istream &operator>>(istream &is, node *&head)
{
    take_input(head);
    return is;
}
void reverse_ll(node *&head)
{
    node *prev = NULL, *cur = head, *next;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}
void reverse_recursive(node *&head, node *cur, node *prev)
{
    if (cur == NULL)
    {
        head = prev;
        return;
    }
    reverse_recursive(head, cur->next, cur);
    cur->next = prev;
}
node *reverse_recursive2(node *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    node *shead = reverse_recursive2(head->next);

    head->next->next = head;
    head->next = NULL;
    return shead;
}
node *midpoint(node *head)
{
    if (head == NULL or head->next == NULL)
        return head;
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
node *kth_node_from_end(node *head, int k)
{
    node *fast = head, *slow = head;
    int i = 1;
    while (i <= k and fast != NULL)
    {
        fast = fast->next;
        i++;
    }
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
node *merge_ll(node *a, node *b)
{
    // base case
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    // recursive case
    node *c;
    if (a->data < b->data)
    {
        c = a;
        c->next = merge_ll(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge_ll(a, b->next);
    }
    return c;
}
node *merge_sort_ll(node *head)
{
    // base case
    if (head == NULL or head->next == NULL)
        return head;
    // recursive case
    // 1. Break
    node *mid = midpoint(head);
    node *a = head;
    node *b = mid->next;
    mid->next = NULL;

    // 2. Sort both ll recursively
    a = merge_sort_ll(a);
    b = merge_sort_ll(b);

    // 3. Merge two sorted LL
    node *merged = merge_ll(a, b);
    return merged;
}

// Floyd's Cycle
bool detect_cycle(node *head)
{
    node *slow = head, *fast = head;
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}

int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    node *a = NULL, *b = NULL;

    // take_input(head);
    // print_ll(head);
    cin >> a;
    // cin >> b;
    cout << a;
    // cout << b;
    node *sorted = merge_sort_ll(a);
    cout << sorted;
    return 0;
}