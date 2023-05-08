//https://leetcode.com/problems/isomorphic-strings/description/
/*Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character,
but a character may map to itself.

 */

class Solution {
public:

    bool helper(string s, string t)
    {
            unordered_map<char, char> mp;

        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                if(mp[s[i]]!=t[i]) return false;
            }else
            {
                mp[s[i]] = t[i];
            }
        }

        return true;
    }
    bool isIsomorphic(string s, string t) {

        return helper(s,t) && helper(t,s);
         
        
    }
};
