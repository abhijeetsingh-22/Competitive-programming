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
void input_head(node *&head, int d)
{
    // if (head == NULL)
    // {
    //     head = new node(d);
    //     return;
    // }
    node *temp = head;
    head = new node(d);
    head->next = temp;
}
void print_ll(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
        // break;
    }
    cout << endl;
    // temp=temp->next;
    // cout<<temp->next->next->next->data;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    node *head;
    input_head(head, 5);
    input_head(head, 4);
    input_head(head, 3);
    input_head(head, 2);
    input_head(head, 1);
    print_ll(head);
    cout << "exit";
    return 0;
}