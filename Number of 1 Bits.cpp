//https://leetcode.com/problems/number-of-1-bits/solutions/

//Subtracting 1 from a decimal number flips all the bits after the rightmost set bit(which is 1) including the rightmost set bit. 
//So if we subtract a number by 1 and do it bitwise & with itself (n & (n-1)), we unset the rightmost set bit.
//If we do n & (n-1) in a loop and count the number of times the loop executes, we get the set bit count. 

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        while (n) {
            n &= (n - 1);
            count++;
        }
        
        return count;
    }
};
