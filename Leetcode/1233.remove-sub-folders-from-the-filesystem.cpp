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
        // TC O(N) sc->O(n)
        //  Trie t;

        // for (string &path : folder)
        // {
        //     t.insert(path);
        // }
        // t.filter_sub_folders(ans);
        vector<string> ans;
        if (folder.size() == 1)
            return folder;
        sort(folder.begin(), folder.end());
        int parent_idx = 0, cur_idx = 1, n = folder.size();
        ans.push_back(folder[0]);
        while (cur_idx < n)
        {
            int parent_size = folder[parent_idx].size();
            int cur_size = folder[cur_idx].size();
            int i;
            for (i = 0; i < parent_size and i < cur_size; i++)
                if (folder[parent_idx][i] != folder[cur_idx][i])
                    break;
            if (i != parent_size or (i < cur_size and folder[cur_idx][i] != '/'))
            {
                ans.push_back(folder[cur_idx]);
                parent_idx = cur_idx;
            }
            cur_idx++;
        }
        return ans;
    }
};
// @lc code=end
