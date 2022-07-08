#include <bits/stdc++.h>
using namespace std;
#define ll long long

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_head(node *&head, int data)
{
    node *temp = head;
    head = new node(data);
    head->next = temp;
    if (temp != NULL)
        temp->prev = head;
}
void print_ll(node *head, bool reverse = false)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        if (reverse == true)
            temp = temp->prev;
        else
            temp = temp->next;
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    node *head = NULL;
    insert_at_head(head, 5);
    insert_at_head(head, 4);
    insert_at_head(head, 3);
    insert_at_head(head, 2);
    insert_at_head(head, 1);
    insert_at_head(head, 0);
    print_ll(head);
    while (head->next != NULL)
        head = head->next;
    print_ll(head, true);
    // cout<<head
    return 0;
}