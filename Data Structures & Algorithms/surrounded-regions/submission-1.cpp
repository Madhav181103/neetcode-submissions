class Solution {
   public:
    void dfs(int row, int col, vector<vector<char>>& board, int m, int n) {
        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != 'O') return;
        board[row][col] = 'T';
        dfs(row - 1, col, board, m, n);
        dfs(row + 1, col, board, m, n);
        dfs(row, col + 1, board, m, n);
        dfs(row, col - 1, board, m, n);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(i, 0, board, m, n);
            if (board[i][n - 1] == 'O') dfs(i, n - 1, board, m, n);
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') dfs(0, j, board, m, n);
            if (board[m - 1][j] == 'O') dfs(m - 1, j, board, m, n);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'T')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};
