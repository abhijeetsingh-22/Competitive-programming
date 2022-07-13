#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack
{
private:
    vector<T> v;

public:
    void push(T data)
    {
        v.push_back(data);
    }
    bool empty()
    {
        return v.size() == 0;
    }
    void pop()
    {
        if (!empty())
        {

            v.pop_back();
        }
    }
    T top() { return v.back(); }
};
void transfer(stack<int> &s1, stack<int> &s2)
{
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
}
void reverse_recursive(stack<int> &s1)
{
    if (s1.empty())
        return;

    int x = s1.top();
    s1.pop();
    reverse_recursive(s1);
    stack<int> s2;
    transfer(s1,s2);
    s1.push(x);
    transfer(s2,s1);
}
int main()
{
    stack<int> s;
    for (int i = 65; i < 71; i++)
    {
        s.push(i);
    }
    reverse_recursive(s);
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}