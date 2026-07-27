class Solution {
public:
    vector<vector<string>> ans;
    bool isSafe(int row,int col,vector<string> &board,int n){
        int r=row;
        int c=col;
        while(r>=0 && c>=0){
            if(board[r][c]=='Q')return false;
            r--;
            c--;
        }
        r=row;
        c=col;
        while(r<n && c>=0){
            if(board[r][c]=='Q')return false;
            r++;
            c--;
        }
        r=row;
        c=col;
        while(c >= 0) {
        if(board[r][c] == 'Q') return false;
            c--;
        }
        return true;
    }
    void  helper(int col,vector<string> &board,int n){
        if(col==n){
            ans.push_back(board);
            return ;
        }
        for(int i=0;i<n;i++){
            if(isSafe(i,col,board,n)){
            board[i][col]='Q';
            helper(col+1,board,n);
            board[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s(n,'.');
        for(int i =0;i<n;i++){
            board[i]=s;
        }
        helper(0,board,n);
        return ans;
    }
};