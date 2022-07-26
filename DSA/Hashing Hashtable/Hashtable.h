#include <bits/stdc++.h>
using namespace std;

template <typename T>
class node
{
public:
    string key;
    T value;
    node<T> *next;

    node(string key, T value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
};

template <typename T>
class HashTable
{
    int table_size;
    node<T> **table;
    int hash_fn(string key)
    {
        int idx = 1;
        int p = 1;
        for (auto c : key)
        {
            idx = idx + (c * p) % table_size;
            idx = idx % table_size;
            p = (p * 27) % table_size;
        }
        return idx;
    }

public:
    HashTable(int table_size = 7)
    {
        this->table_size = table_size;
    }

    void insert(string key, T value)
    {
        int idx = hash_fn(key);
        node<T> *temp = new node<T>(key, value);
        temp->next = table[idx];
        table[idx] = temp;
    }
    void print()
    {
        for (int i = 0; i < table_size; i++)
        {
            cout << i << " ->";
            for (auto p : table[i])
            {
                cout << p.first << " " << p.second << ",";
            }
            cout << endl;
        }
    }
    /*
    void erase(string key)
    {
    }
    T *search(string key)
    {
    }
    */
};

// int main()
// {
//     return 0;
// }