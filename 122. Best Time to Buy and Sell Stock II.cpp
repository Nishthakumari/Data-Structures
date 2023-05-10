https://www.youtube.com/watch?v=Q7v239y-Tik
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 /*
    Approach: 
    If stock price is going up tomorrow just buy it today and sell it tomorrow.
    
    Time complexity : O(n)
    Space complexity: O(1)

    n is number of days.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i=1;i<prices.size();i++)
        {
             // look into the next day and if you are making profit just buy it today.
            if(prices[i]>prices[i-1])
            {
                ans=ans+ (prices[i]-prices[i-1]);
            }

        }

        return ans;
    }
};
