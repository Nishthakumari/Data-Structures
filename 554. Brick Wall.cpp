//https://leetcode.com/problems/brick-wall/description/
/*
    Approach: 
    Store the count of the end of the brick for each row in a hash and keep the track
    of max number of brick that ends at same position, return rows - max.
    
    Time complexity : O(n x m)
    Space complexity: O(n x m)

    n is number of rows, m is max brick in a row.
*/

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> m;
  
        int Max = 0;

        for(int i=0;i<wall.size();i++)
        {
            int sum=0;
            for(int j=0;j<wall[i].size()-1;j++)
            {
                sum  = sum + wall[i][j];
                m[sum]++;

                Max = max(Max, m[sum]);
            }
        }

        int crosses =  wall.size()-Max;
        return crosses;

    }
    
};
