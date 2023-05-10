//https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/description/

/*
    Approach: 
    Keep the track of the ratios in a hash map
    
    Time complexity : O(n)
    Space complexity: O(n)

    n is number of rectangles
*/

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
         int n = rectangles.size();
        map<pair<int, int>, int> mp;
        long long result = 0;
        
        for(int i = n-1; i >= 0; i--) {
            int gcd = __gcd(rectangles[i][0],rectangles[i][1]);
            
            //Have I seen this pair
            if(mp.find({rectangles[i][0]/gcd, rectangles[i][1]/gcd}) != end(mp))
                result += mp[{rectangles[i][0]/gcd, rectangles[i][1]/gcd}];

            //Increase the count
            mp[{rectangles[i][0]/gcd, rectangles[i][1]/gcd}]++;
        }
        return result;
    }
};
