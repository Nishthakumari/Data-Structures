
https://leetcode.com/problems/maximum-number-of-removable-characters/description/

class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        
        int lo=0,hi=removable.size(), ans=0;
        while(lo<=hi)
        {
            int k=(lo+hi)/2;
            if(isvalid(s,p,removable,k))
            {

            ans=k; 
                lo=k+1;
                }
            else
            {

                hi=k-1;
            }
            
            
        
        }
        return ans;
        
    }
    
    bool isvalid(string s, string p,vector<int>& removable, int k )
    {
        if(k>(s.size()-p.size()))  return false;

        string temp;
        for(int i=0;i<k;i++)
        {
            s[removable[i]]+=100;
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a' && s[i]<='z')
                temp.push_back(s[i]);
        }
        if(isSubSequence(p, temp)) return true;
        
        return false;
    
        
    }
    

bool isSubSequence(string str1, string str2)
{
    int m=str1.size(), n=str2.size();
    int j = 0; 
 
    for (int i = 0; i < n && j < m; i++)
        if (str1[j] == str2[i])
            j++;
 
    return (j == m);
}
};
