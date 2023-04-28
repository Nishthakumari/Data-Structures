//https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {

 void helper(vector<string> &ans, string &path, int index, string digits, vector<string> &letters){

     if(index == digits.size())
     {
         ans.push_back(path);
         return;
     }

     for(int i=0;i<letters[(int)(digits[index]-'0')].size();i++)
     {
         path.push_back(letters[(int)(digits[index]-'0')][i]);
         helper(ans, path, index+1, digits, letters);
         path.pop_back();
     }
 }

public:
    vector<string> letterCombinations(string digits) {
        
        if(digits.empty()) return {};

        vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno","pqrs", "tuv", "wxyz"};

        vector<string> ans;
        string path = "";

        helper(ans, path, 0, digits, letters);

        return ans;

    }
};
