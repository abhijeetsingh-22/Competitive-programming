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
        this->next = nullptr;
    }
    ~node()
    {
        if (next)
        {
            delete next;
        }
    }
};

template <typename T>
class HashTable
{
    int table_size;
    int cur_size;
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
    void re_hash()
    {
        int old_table_size = table_size;
        table_size = 2 * table_size;

        node<T> **old_table = table;
        table = new node<T> *[table_size];
        cur_size = 0;
        for (int i = 0; i < old_table_size; i++)
        {
            node<T> *cur = old_table[i];
            while (cur != nullptr)
            {
                insert(cur->key, cur->value);
                cur = cur->next;
            }
            if (old_table[i])
                delete old_table[i];
        }
        delete[] old_table;
    }

public:
    HashTable(int table_size = 7)
    {

        this->table_size = table_size;
        this->table = new node<T> *[table_size];
        this->cur_size = 0;
        for (int i = 0; i < table_size; i++)
        {
            table[i] = nullptr;
        }
    }

    void insert(string key, T value)
    {
        int idx = hash_fn(key);
        node<T> *temp = new node<T>(key, value);
        temp->next = table[idx];
        table[idx] = temp;
        cur_size++;
        float load_factor = cur_size / (1.0 * table_size);
        // cout<<"hashing "<<cur_size<<" "<< table_size<<endl;
        if (load_factor > 0.7)
        {
            re_hash();
        }
    }
    void print()
    {
        for (int i = 0; i < table_size; i++)
        {
            cout << i << " ->";
            node<T> *temp = table[i];
            while (temp != nullptr)
            {
                cout << temp->key << " " << temp->value << ",";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void erase(string key)
    {
        int idx = hash_fn(key);
        node<T> *cur = table[idx];
        if (cur and cur->key == key)
        {
            table[idx] = cur->next;
            cur->next = nullptr;
            delete cur;
            return;
        }
        else
        {

            while (cur and cur->next != nullptr)
            {
                if (cur->next->key == key)
                {
                    node<T> *temp = cur->next;
                    cur->next = cur->next->next;
                    delete temp;
                    return;
                }
                cur = cur->next;
            }
        }
        return;
    }

    T *search(string key)
    {
        int idx = hash_fn(key);
        node<T> *temp = table[idx];
        while (temp != nullptr)
        {
            if (temp->key == key)
            {
                return &temp->value;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};
int main()
{
    HashTable<int> menu;
    menu.insert("burger", 110);
    menu.insert("salad", 199);
    menu.insert("meal", 200);
    menu.insert("Noodles", 80);
    menu.insert("soup", 150);
    // menu.insert("cold drink", 20);
    // menu.insert("sandwich", 90);
    // menu.insert("cake", 500);

    menu.print();
    // cout << *menu.search("burger") << endl;
    // menu.erase("sandwich");
    // menu.erase("salad");
    // menu.print();
    // cout<<*menu.search("bur")<<endl;
    // cout<<menu.search("burge");

    return 0;
}