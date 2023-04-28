https://leetcode.com/problems/combination-sum/description/

class Solution {

private:
    void helper(vector<vector<int>> &ans, vector<int> &path, int index, int target, vector<int> &nums){
        if(index == nums.size())
        {
            if(target ==0)
            {
                ans.push_back(path);
            }
            return;
        }

        if(nums[index]<=target){
        path.push_back(nums[index]);
        helper(ans, path, index, target-nums[index], nums);
        path.pop_back();
        }
        helper(ans, path, index+1, target, nums);

    }
public:

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> path;
        helper(ans, path, 0, target, candidates);
        return ans;
    }
};
