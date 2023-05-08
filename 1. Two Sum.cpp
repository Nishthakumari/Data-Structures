/*
    Given int array & target, return indices of 2 nums that add to target
    Ex. nums = [2,7,11,15] & target = 9 -> [0,1], 2 + 7 = 9

    At each num, calculate complement, if exists in hash map then return

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> mp;
        int n= nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
            {
                return {i, mp[target-nums[i]]};
            }

            mp[nums[i]]=i;
        }
        return {};
    }
};
