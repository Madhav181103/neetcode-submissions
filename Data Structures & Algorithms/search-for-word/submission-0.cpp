class Solution {
public:
    int m, n;

    bool dfs(vector<vector<char>>& board, string& word,
             int row, int col, int idx,
             vector<vector<bool>>& visited) {

        if (idx == word.size())
            return true;

        if (row < 0 || col < 0 || row >= m || col >= n)
            return false;

        if (visited[row][col])
            return false;

        if (board[row][col] != word[idx])
            return false;

        visited[row][col] = true;

        bool found =
            dfs(board, word, row + 1, col, idx + 1, visited) ||
            dfs(board, word, row - 1, col, idx + 1, visited) ||
            dfs(board, word, row, col + 1, idx + 1, visited) ||
            dfs(board, word, row, col - 1, idx + 1, visited);

        visited[row][col] = false;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        m = board.size();
        n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0, visited))
                    return true;
            }
        }

        return false;
    }
};