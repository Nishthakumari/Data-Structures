https://leetcode.com/problems/arranging-coins/description/

https://leetcode.com/problems/arranging-coins/solutions/1560442/c-python-4-simple-solutions-w-explanation-brute-force-binary-search-math-beats-100/

//Binary search
class Solution {
public:
    int arrangeCoins(int n) {
        int l = 1, r = n, ans;
		long rows, coinsNeeded;
        while(l <= r) {
            rows = l + ((r-l) >> 1);                            // finding mid of range [l, r]
            coinsNeeded = (rows * (rows + 1)) >> 1;             // coins needed for 'rows' number of row
            if(coinsNeeded <= n) l = rows + 1, ans = rows;      // if available coins are sufficient
            else r = rows - 1;                                  // coins insufficient, eliminate the half greater than rows
        }
        return ans;
    }
};

//Brute force
class Solution {
public:
    int arrangeCoins(int n) {
        int rows = 1;
        while(n > 0) {     // iterate till we have coins left
            rows++;        // move to next row
            n -= rows;     // fill current row by subtracting from available coins
        }
        return rows - 1;  
    }
};
