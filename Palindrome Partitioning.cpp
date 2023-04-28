//https://leetcode.com/problems/palindrome-partitioning/description/

class Solution {
public:

    bool isPalindrome(string s, int i, int j)
    {
            while(i<j)
            {
                if(s[i]!=s[j]) return false;
                i++;
                j--;
            }

            return true;
    }

    void helper(vector<vector<string>> &ans, vector<string> &path, string s, int index)
    {
        if(index == s.size())
        {
            ans.push_back(path);
            return;
        }
    

        for(int i=index;i<s.size();i++)
        {
            if(isPalindrome(s, index, i))
            {
                path.push_back(s.substr(index, i-index+1));
                helper(ans, path, s, i+1);
                path.pop_back();
            }
         
        }
    }


    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        
        helper(ans, path, s, 0);

        return ans;
        
    }
};
