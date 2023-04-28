//https://leetcode.com/problems/permutations/description/

class Solution {
public:

    void permuteHelper(vector<int> &nums, vector<vector<int>> &ans, int index, vector<int> &path, vector<int> &freq)
    {

            if(index == nums.size()) {
                ans.push_back(path);
            }

            for(int i=0;i<nums.size();i++)
            {
                if(freq[i]==0){
                path.push_back(nums[i]);
                freq[i]=1;
                permuteHelper(nums, ans, index+1, path, freq );
                freq[i] =0;
                path.pop_back();
                }

            }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> freq(n,0);
        vector<int> path;

        permuteHelper(nums, ans, 0, path, freq );

        return ans;
    }
};
