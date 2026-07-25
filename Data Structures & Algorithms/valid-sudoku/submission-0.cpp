class Solution {
   public:
    bool check(vector<vector<char>>& board,int i , int j) {
        char number =   board[i][j];
        for(int row = 0 ;row<9 ; row++){
            if(board[row][j]==number && row!=i)return false;
        }
    
    for(int col = 0 ;col<9 ; col++){
            if(board[i][col]==number && col!=j)return false;
        }

        int row = (i/3)*3;
        int col = (j/3)*3;
        for(int a=row;a<row+3;a++){
            for(int b=col;b<col+3;b++){
        if((a!=i||b!=j) && board[a][b]==number)return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (!check(board, i, j)) return false;
                }
            }
        }
        return true;
    }
};
