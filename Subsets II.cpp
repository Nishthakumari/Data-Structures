//https://leetcode.com/problems/subsets-ii/description/

class Solution {

private:
    void helper( vector<vector<int>> &ans, vector<int>&path, vector<int>&nums, int index)
    {
       
        ans.push_back(path);
       
        for(int i=index;i<nums.size();i++)
        {
            if(i!=index && nums[i]==nums[i-1]) continue;
            path.push_back(nums[i]);
            helper(ans, path, nums, i+1);
            path.pop_back();

        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> path;
        helper(ans, path, nums, 0);
        return ans;
    }
};
