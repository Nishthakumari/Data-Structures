//https://leetcode.com/problems/valid-sudoku/description/
/*
    Determine if a 9x9 Sudoku board is valid (no repeats)

    Boolean matrices to store seen values. Check rows, cols, 3x3 sub-boxes

    Time: O(cnt^2)
    Space: O(cnt^2)
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int used1[9][9]={0}, used2[9][9]={0}, used3[9][9]={0};

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]!='.'){
                int val = board[i][j]-'0'-1;
                int k= i/3*3+j/3;

                if(used1[i][val]|| used2[j][val] || used3[k][val]){
                    return false;
                }

                used1[i][val]=used2[j][val]=used3[k][val]=1;
                }
            }
        }

        return true;
    }
};
