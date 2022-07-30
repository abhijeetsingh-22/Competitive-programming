/*
 * @lc app=leetcode id=1233 lang=cpp
 *
 * [1233] Remove Sub-Folders from the Filesystem
 */

// @lc code=start
class node
{

public:
    unordered_map<string, node *> children;
    bool terminal;
    node()
    {
        terminal = false;
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

    void insert(string &path)
    {

        node *cur = root;
        string cur_folder_name;
        for (char &c : path)
        {
            if (c != '/')
                cur_folder_name += c;
            else if (cur_folder_name.size() > 0)
            {
                if (!cur->children.count(cur_folder_name))
                    cur->children[cur_folder_name] = new node();
                cur = cur->children[cur_folder_name];
                cur_folder_name.clear();
            }
        }
        if (!cur->children.count(cur_folder_name))
            cur->children[cur_folder_name] = new node();
        cur = cur->children[cur_folder_name];

        cur->terminal = true;
    }
    void dfs(node *root, string cur_path, vector<string> &ans)
    {
        if (root->terminal)
        {
            ans.push_back(cur_path);
            return;
        }

        for (auto &p : root->children)
        {
            dfs(p.second, cur_path + "/" + p.first, ans);
        }
    }
    void filter_sub_folders(vector<string> &ans)
    {
        dfs(root, "", ans);
    }
};
class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        Trie t;

        for (string &path : folder)
        {
            t.insert(path);
        }
        vector<string> ans;
        t.filter_sub_folders(ans);
        return ans;
    }
};
// @lc code=end
