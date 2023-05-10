//https://leetcode.com/problems/top-k-frequent-elements/description/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> elementCount;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        elementCount[nums[i]]++;

        vector<vector<int>> frequency(n+1);

        for(auto element : elementCount)
        {
                frequency[element.second].push_back(element.first);
        }

        int count=0;
        for(int i=frequency.size()-1;i>=0;i--)
        {
            if(frequency[i].size()>1)
            sort(frequency[i].begin(), frequency[i].end(), greater<int>());

            for(auto element: frequency[i])
            {
                ans.push_back(element);
                count++;
                if(count>=k) return ans;
            }


        }

        return ans;

    }
};
