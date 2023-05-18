https://leetcode.com/problems/unique-binary-search-trees/

https://leetcode.com/problems/unique-binary-search-trees/solutions/1565543/c-python-5-easy-solutions-w-explanation-optimization-from-brute-force-to-dp-to-catalan-o-n/

❌ Solution - I (Brute-Force) [TLE]

class Solution {
public:
    int numTrees(int n) {
        if(n <= 1) return 1;
        int ans = 0;
        for(int i = 1; i <= n; i++) 
            ans += numTrees(i-1) * numTrees(n-i);
        return ans;
    }
};

Time Complexity : O(3N), where N is the given number of nodes in BST.
Space Complexity : O(N), the maximum recursive stack depth.
  
  
  ✔️ Solution - II (Dynamic Programming - Memoization)
  
  class Solution {
public:
    int dp[20]{};
    int numTrees(int n) {
        if(n <= 1) return 1;
        if(dp[n]) return dp[n];
        for(int i = 1; i <= n; i++) 
            dp[n] += numTrees(i-1) * numTrees(n-i);
        return dp[n];
    }
};


Time Complexity : O(N2)
Here we calculate numTrees(i) (for 1<=i<=N) only once and memoize it which will take O(N). For calculating each of numTrees(i), we need N iterations to calculate numTrees(0)*numTrees(i) + numTrees(1)*numTrees(i-1) + numTrees(2)*numTrees(i-2)+ ... + numTrees(i)*numTrees(0). Thus, the overall time complexity becomes O(N*N).
Space Complexity : O(N), required for recursion and memoization

✔️ Solution - III (Dynamic Programming - Tabulation)
  
  class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i++) 
            for(int j = 1; j <= i; j++)
                dp[i] += dp[j-1] * dp[i-j];
        return dp[n];
    }
};

Time Complexity : O(N2), we iterate over the range i=[2, n] and iteratively calculate dp[i]. The total number of operations performed equals 2+3+4+5..n = (n*(n+1)/2)-1 ≈ O(N2)
Space Complexity : O(N), required to store the results in dp

✔️ Solution - IV (Catalan Numbers)
  
 
  
  class Solution {
public:
    long ncr(int n, int r) {
        long ans = 1;
        for(int i = 0; i < r; i++) {
            ans *= n-i;
            ans /= i+1;
        }
        return ans;   
    }
    int numTrees(int n) {
        return ncr(2*n, n) / (n + 1);
    }
};

