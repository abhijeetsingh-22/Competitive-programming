/*
 * @lc app=leetcode id=648 lang=cpp
 *
 * [648] Replace Words
 */

// @lc code=start
struct node
{
    node *childern[26];
    bool is_terminal;

    node()
    {
        is_terminal = false;
        for (int i = 0; i < 26; i++)
            childern[i] = nullptr;
    }
};
class Trie
{
    node *root;

public:
    Trie()
    {
        root = new node();
    }

    void insert(string &s)
    {
        node *cur = root;
        for (char &c : s)
        {
            if (cur->is_terminal)
                return;
            if (!cur->childern[c - 'a'])
                cur->childern[c - 'a'] = new node();
            cur = cur->childern[c - 'a'];
        }
        cur->is_terminal = true;
    }

    string find_root(string &s)
    {

        node *cur = root;
        string word;
        for (char &c : s)
        {
            if (!cur->childern[c - 'a'])
                return s;
            cur = cur->childern[c - 'a'];
            word += c;
            if (cur->is_terminal)
            {
                return word;
            }
        }
        return s;
    }
};
class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        string ans;
        Trie t;
        for (string &s : dictionary)
        {
            t.insert(s);
        }
        string cur_word;
        string word;
        istringstream ss(sentence);

        for (; ss >> word;)
        {
            ans += t.find_root(word);
            ans += ' ';
        }
        ans.pop_back();

        // for (char &c : sentence)
        // {
        //     if (c != ' ')
        //         cur_word.push_back(c);
        //     else
        //     {
        //         if (ans.size() > 0)
        //             ans = ans + " " + t.find_root(cur_word);
        //         else
        //             ans = ans + t.find_root(cur_word);
        //         cur_word.clear();
        //     }
        // }
        // if (ans.size() > 0)
        //     ans = ans + " " + t.find_root(cur_word);
        // else
        //     ans = ans + t.find_root(cur_word);
        return ans;
    }
};
// @lc code=end
