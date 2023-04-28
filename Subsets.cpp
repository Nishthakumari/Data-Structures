//https://leetcode.com/problems/subsets/description/

class Solution {

private:

void subset(vector<vector<int>> &ans, vector<int> &path, vector<int> &nums, int index)
{
    if(index == nums.size())
    {
        ans.push_back(path);
        return;
    }

    path.push_back(nums[index]);
    subset(ans, path, nums, index+1 );

    path.pop_back();
    subset(ans, path, nums, index+1);
  
}


public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        
        subset(ans, path, nums, 0);

        return ans;
        
    }
};
