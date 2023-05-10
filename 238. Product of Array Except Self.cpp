class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //create prefix and sufffix product array.
        int n= nums.size();
        vector<int> prefix(n), suffix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        prefix[i]=prefix[i-1]*nums[i];

        suffix[n-1]= nums[n-1];
        for(int i=n-2;i>=0;i--)
        suffix[i] = suffix[i+1]*nums[i];

        vector<int> ans(n,1);

        for(int i=0;i<n;i++)
        {
            if(i>0)
            ans[i]*=prefix[i-1];

            if(i<n-1)
            ans[i]*=suffix[i+1];
        }

        return ans;




    }
};
