/*
 * @lc app=leetcode id=804 lang=cpp
 *
 * [804] Unique Morse Code Words
 */

// @lc code=start
class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        unordered_set<string> set;
        vector<string> code({".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."});

        for (string &s : words)
        {
            string cur_word = "";
            for (char &c : s)
                cur_word += code[c - 'a'];
            set.insert(cur_word);
        }
        return set.size();
    }
};
// @lc code=end
