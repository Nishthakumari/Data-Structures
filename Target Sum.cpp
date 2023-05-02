//https://leetcode.com/problems/target-sum/description/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum =0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
                sum  =  sum + nums[i];
        }

        if((sum+target)%2==1) return 0;
        if(sum+target<0)  return 0;

        int m = (sum+target)/2;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        dp[0][0]=1;

        for(int i=1;i<m+1;i++)
        {
            dp[0][i] = 0;
        }

        for(int i=1;i<n+1;i++)
        {
            if(nums[i-1]==0)
            dp[i][0] = 2*dp[i-1][0];
            else
            dp[i][0] = dp[i-1][0];
        }

        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(nums[i-1]>j)
                {
                    dp[i][j]  = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j]+dp[i-1][j-nums[i-1]];
                }
            }
        }

        return dp[n][m];

    }
};
