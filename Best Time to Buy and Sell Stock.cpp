//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int mn=prices[0];
        for(int i=0;i<prices.size();i++)
        {
            mn=min(mn, prices[i]);
            maxprofit=max(maxprofit, prices[i]-mn);
        }
        
        return maxprofit;
    }
};
