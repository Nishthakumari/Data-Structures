//https://leetcode.com/problems/combination-sum-iv/description/

/*
Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.
*/


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<unsigned int> dp(target+1);
        dp[0]=1;

        for(int i=1;i<=target;i++)
        {
       
            for(int j=0;j<nums.size();j++){
                if(nums[j]<=i)
                  dp[i] = dp[i]+dp[i-nums[j]];
            }
        }

        return dp[target];
    }
};


// With Recusion

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
       vector<int> dp(target+1, -1);
       dp[0]=1;
       cs(nums, target, dp);
       return dp[target];

    }

    int cs(vector<int> &nums, int target, vector<int> &dp)
    {
       
        if(dp[target]>-1)  return dp[target];

        int count = 0;

        for(int i=0;i<nums.size();i++)
        {
            if(target-nums[i]>=0)
            count += cs(nums, target-nums[i], dp);
        }

        return dp[target]=count;
    }
};

