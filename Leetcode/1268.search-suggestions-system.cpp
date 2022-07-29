/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 */

// @lc code=start
// #include <bits/stdc++.h>
// using namespace std;
struct node
{
public:
    vector<node *> children{vector<node *>(26, NULL)};
    bool terminal = false;
};

class trie
{
    node *root;

public:
    trie()
    {
        root = new node();
    }

    void insert(string &s)
    {
        node *cur = root;
        for (char c : s)
        {
            if (!cur->children[c - 'a'])
            {
                cur->children[c - 'a'] = new node();
            }
            cur = cur->children[c - 'a'];
        }
        cur->terminal = true;
    }
    void dfs(node *root, string &word, vector<string> &cur_ans)
    {
        if (cur_ans.size() >= 3)
            return;
        if (root->terminal)
        {
            cur_ans.push_back(word);
        }
        for (char c = 'a'; c <= 'z'; c++)
        {
            if (root->children[c - 'a'])
            {
                word += c;
                dfs(root->children[c - 'a'], word, cur_ans);
                word.pop_back();
            }
        }
    }
    vector<vector<string>> suggestion(string &search)
    {

        vector<vector<string>> ans;
        string cur_word;
        node *cur = root;
        bool can_search = true;
        for (char ch : search)
        {
            cur_word.push_back(ch);
            vector<string> cur_ans;
            if (cur->children[ch - 'a'] and can_search)
            {
                cur = cur->children[ch - 'a'];

                dfs(cur, cur_word, cur_ans);
            }
            else
            {
                can_search = false;
            }
            ans.push_back(cur_ans);
        }
        return ans;
    }
};

class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        trie t;
        for (string s : products)
        {
            t.insert(s);
        }
        return t.suggestion(searchWord);
    }
};
// @lc code=end
