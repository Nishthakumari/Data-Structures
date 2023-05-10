//https://leetcode.com/problems/longest-consecutive-sequence/description/
/*
    Given unsorted array, return length of longest consecutive sequence
    Ex. nums = [100,4,200,1,3,2] -> 4, longest is [1,2,3,4]

    Store in hash set, only check for longer seq if it's the beginning

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;

        for(int i=0;i<nums.size();i++){
            hash.insert(nums[i]);

        }
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(hash.find(nums[i]-1)==hash.end())
            {
                int j= nums[i];
                int count=0;

                while(hash.find(j)!=hash.end())
                {
                    count++;
                    j++;
                }
                ans= max(ans, count);
            }

            
        }

        return ans;
    }
};
