/*
    Given int array & sliding window size k, return max sliding window
    Ex. nums = [1,3,-1,-3,5,3,6,7] k = 3 -> [3,3,5,5,6,7]
    Sliding window deque, ensure monotonic decr, leftmost largest
    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       vector<int> ans;
        list<int> l;
        int i=0;
        int j=0;
        
        if (k>nums.size()) // edge case
        {
            ans.push_back(*max_element(l.begin(),l.end()));
            return ans;
        }
        
        while (j<nums.size())
        {
            while(l.size()>0 && l.back() <nums[j])
            {
                l.pop_back();
            }
            l.push_back(nums[j]);
            if ((j-i+1)<k)
                j++;
            else if (j-i+1==k)
            {
                ans.push_back(l.front());
                if (l.front()==nums[i])
                    l.pop_front();
                i++;
                j++;
            }
            
        }
        return ans;
    }
};
