/*
 * @lc app=leetcode id=1381 lang=cpp
 *
 * [1381] Design a Stack With Increment Operation
 */

// @lc code=start
class CustomStack
{
private:
    int maxSize;
    int *arr, *inc;
    int top;

public:
    // push pop TC->O(1)
    // increment TC-> O(n)
    // we can use lazy increment for TC->O(1) and SC-> O(n)
    CustomStack(int maxSize)
    {
        this->maxSize = maxSize;
        this->top = -1;
        this->arr = new int[maxSize];
        this->inc = new int[maxSize];
    }

    void push(int x)
    {
        if (top == maxSize - 1)
            return;
        else
        {
            arr[++top] = x;
            inc[top] = 0;
        }
    }

    int pop()
    {
        if (top == -1)
            return -1;
        int data = arr[top];
        int in = inc[top];
        if (top > 0)
            inc[top - 1] += in;
        top--;
        return data + in;
    }

    void increment(int k, int val)
    { // TC-> O(n)
        // for (int i = 0; i < k and i <= top; i++)
        // {
        //     arr[i] += val;
        // }

        // TC-> O(1) with lazy increment;
        int i = min(k, top + 1) - 1;
        if (i < 0)
            return;
        if (i >= 0)
            inc[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
// @lc code=end
