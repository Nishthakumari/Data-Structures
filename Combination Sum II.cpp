
https://leetcode.com/problems/combination-sum-ii/description/

class Solution {

private:
    void helper( vector<vector<int>> &ans, vector<int>&path, vector<int>&nums, int index, int target)
    {
       if(target==0)
        ans.push_back(path);
       
        for(int i=index;i<nums.size();i++)
        {
            if(i!=index && nums[i]==nums[i-1]) continue;

            if(nums[i]<=target){
            path.push_back(nums[i]);
            helper(ans, path, nums, i+1, target-nums[i]);
            path.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        helper(ans, path, candidates, 0, target);
        return ans;
    
    }
};
