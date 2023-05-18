https://leetcode.com/problems/valid-perfect-square/description/


//Brute Force

class Solution {

// 1=1
// 1+3=4
// 1+3+5=9
// 1+3+5+7=16
// and so on ..............

public:
    bool isPerfectSquare(int num) {
         int a=1;

        
        while(num>0){
            num-=a;
            a+=2;
        }
        return(num==0);
    }
};

//Binary Search
class Solution {                                //  O(log(n)) // Most Optimal
public:
    bool isPerfectSquare(int num) {
        int low = 1, high = num; 
        while(low <= high){
            long long int mid = low + (high - low) / 2;
            if(mid * mid == num)
                return 1;
            else if(mid * mid < num)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return 0;
    }
};
