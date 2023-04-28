//https://leetcode.com/problems/word-search/description/

class Solution {

private:
    bool helper(vector<vector<int>> &visited, int index, int i, int j, vector<vector<char>>& board, string word, int m, int n){

        
        
        if(index ==word.size())
        {
            return true;
        }

        if(i<0 || j<0 || i>n-1|| j>m-1 ||word[index]!=board[i][j] || visited[i][j])
        return false;

        visited[i][j]=1;



        bool left = helper(visited, index+1, i+1,j, board, word, m, n);
        bool right = helper(visited, index+1, i-1,j, board, word, m, n);
        bool up = helper(visited, index+1, i,j+1, board, word, m, n);
        bool down = helper(visited, index+1, i,j-1, board, word, m, n);

        visited[i][j]=0;

        return left||right||up||down;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        int n=board.size(), m=board[0].size();
        vector<vector<int>> visited(n, vector<int> (m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    if( helper(visited, 0, i,j, board, word, m, n))
                    return true;
                }
            }
        }
       
        return false;
    }
};
