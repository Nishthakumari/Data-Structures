//https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

/*
    Approach: 
    Traverse the entire array from start to end. Since the numbers are in a range [1, n] we can use this simple trick.
    At every index mark the position arr[arr[i]] as negative.
    Repeat this for every index in the array.
    At the end, which ever places are positive, add them to our answer.
    
    Time complexity: O(n)
    Space complexity: O(1)
    */

Solution 1

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
         vector<int> ans;
        for(auto& c : nums) 
            while(nums[c-1] != c) 
				swap(c, nums[c-1]);               
                // swap till correct index place of c is not occupied by c itself
        for(int i = 1; i <= size(nums); i++)
            if(i != nums[i-1]) ans.push_back(i);  
            // correct index place of i is not occupied by i itself
        return ans;
    }
};


Solution 2
  
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        
        for(int x : nums){                 /* Mark values as negative */
            int currentVal = abs(x);
            nums[currentVal-1] = 0 - abs(nums[currentVal-1]);
        }
        
        for(int i = 1; i <= nums.size(); i++)
            if(nums[i-1] > 0) ans.push_back(i);    /* Find unmarked values */
        
        return ans;
    }
