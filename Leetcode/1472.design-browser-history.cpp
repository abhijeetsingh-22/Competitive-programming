/*
 * @lc app=leetcode id=1472 lang=cpp
 *
 * [1472] Design Browser History
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    string url;
    node *next;
    node *prev;
    node(string homepage)
    {
        this->url = homepage;
        this->next = NULL;
        this->prev = NULL;
    }
};
class BrowserHistory
{
private:
    node *head;
    static void delete_ll(node *head)
    {
        if (head == NULL)
            return;

        node *temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

public:
    BrowserHistory(string homepage)
    {
        head = new node(homepage);
    }

    void visit(string url)
    {
        delete_ll(head->next);
        head->next = new node(url);
        head->next->prev = head;
        head = head->next;
    }

    string back(int steps)
    {
        while (steps-- and head->prev != NULL)
        {
            head = head->prev;
        }
        return head->url;
    }

    string forward(int steps)
    {
        while (steps-- and head->next != NULL)
        {
            head = head->next;
        }
        return head->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end
