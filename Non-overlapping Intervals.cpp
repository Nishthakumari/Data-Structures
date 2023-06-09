//https://leetcode.com/problems/non-overlapping-intervals/description/

class Solution {
public:

    bool static compare(vector<int>&a, vector<int> &b)
    {
        return a[1]<b[1];
    }
   
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return 0;
        int n=intervals.size();
        int ans = 0;

        sort(intervals.begin(), intervals.end(), compare);

        int prev = intervals[0][1];

        for(int i=1;i<n;i++)
        {
                if(intervals[i][0]<prev)
                ans++;
                else
                {
                    prev = intervals[i][1];
                }
        }

        return ans;
    }
};
