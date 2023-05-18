https://leetcode.com/problems/search-insert-position/description/

class Solution {
    public int searchInsert(int[] nums, int target) {
     //min index greater than eq to this   
        
        if(target>nums[nums.length-1])  return nums.length;
        
         int low=0, high=nums.length-1;
        int index=-1;
        while (low<=high)
        {
            int mid = low +(high-low)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target)
            {
                index = mid;
                high =mid-1;
            }else{
                low = mid+1;
            }
        }
        
        return index;
    }
}
