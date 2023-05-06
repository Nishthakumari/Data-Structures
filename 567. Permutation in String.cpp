//https://leetcode.com/problems/permutation-in-string/
/*
    Given 2 strings, return true if s2 contains permutation of s1
    Ex. s1 = "ab", s2 = "eidbaooo" -> true, s2 contains "ba"
    Sliding window, expand + count down char, contract + count up char
    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    bool checkInclusion(string p, string s)
    {
        unordered_map<char,int>m;
        int n=s.length();
        int k=p.length();
        for(auto i:p)
            m[i]++;
        int c=m.size();
        int i=0,j=0;
        while(j<n)
        {
            if(m.count(s[j]))
            {
                m[s[j]]--;
               if(m[s[j]]==0)
                   c--;
            }
            
            if((j-i+1) <k)
                j++;
            
            else if((j-i+1) ==k)
            {
                if(c==0)
                    return true;
                
                if(m.count(s[i]))
                {
                  m[s[i]]++;
                    
                  if (m[s[i]]==1)
                  c++;
                        
                }
                          i++;
                          j++;
            }
           
        }
           return false;
        
    }
};
