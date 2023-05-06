//https://leetcode.com/problems/3sum/description/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i=0;i<(int)nums.size()-2;i++)
        {
            if(i==0 || (i>0 && nums[i]!=nums[i-1]))
            {
                int lo = i+1, high =(int)nums.size()-1, sum=0-nums[i];
                while(lo<high)
                {
                    if(nums[lo]+nums[high]==sum)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[high]);

                        res.push_back(temp);

                        while(lo<high && nums[lo]==nums[lo+1]) lo++;
                        while(lo<high  && nums[high]==nums[high-1]) high--;

                        lo++;
                        high--;
                    }else if(nums[lo]+nums[high]<sum) lo++;
                    else 
                    high--;
                }
            }
        }

        return res;
    }
};
