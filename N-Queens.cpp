//https://leetcode.com/problems/n-queens/description/

class Solution {

private:

    bool isValid(vector<string> board, int x, int y, int n)
    {
        int i =x, j =y;
    
        while(y>0)
        {
            y--;
            if(board[x][y]=='Q') return false;

        }

        x=i;
        y=j;

        while(x>0 && y>0)
        {
            x--;
            y--;
            if(board[x][y]=='Q') return false;

        }


        x=i;
        y=j;

          while(x<n-1 && y>0)
        {
            x++;
            y--;
            if(board[x][y]=='Q') return false;

        }

        return true;
    }

    void helper(vector<vector<string>>  &ans, vector<string>&board, int n, int col){

        if(col == n)
        {
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++)
        {
            if(isValid(board, row, col, n))
            {
             board[row][col]  = 'Q';
              helper(ans, board, n, col+1);   
              board[row][col]  = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
         vector<vector<string>>  ans;
         vector<string> board(n);
         string s(n, '.');
        for(int i=0;i<n;i++)
        {
          board[i]=s;
        }
         helper(ans, board, n, 0);
         return ans;
         }
};
