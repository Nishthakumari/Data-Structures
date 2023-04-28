//https://leetcode.com/problems/counting-bits/description/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v(n+1,0);

        for(int i=1;i<=n;i++)
        {
            if(i%2)
            {
                v[i] = v[i-1]+1;
            }
            else{
                v[i] = v[i/2];
            }
        }
        return v;
    }
};
