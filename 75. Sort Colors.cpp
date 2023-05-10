//https://leetcode.com/problems/sort-colors/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0, high= nums.size()-1, mid=0;
        int temp=0;

        while(mid<=high)
        {
             if(nums[mid]==0)
             {
                 temp= nums[low];
                 nums[low]=nums[mid];
                 nums[mid]=temp;
                 low++;
                 mid++;
             }
             else if(nums[mid]==1)
             {
                 mid++;
             }
             else
             {
                 temp= nums[mid];
                 nums[mid]= nums[high];
                 nums[high]= temp;
                 high--;
             }
        }
    }
};
