class Solution {
   public:
    int dfs(vector<vector<int>>& grid, int row, int col, int m, int n) {
        if (row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == 0) return 0;
        grid[row][col] = 0;
        return 1 + dfs(grid, row - 1, col, m, n) + dfs(grid, row, col - 1, m, n) +
               dfs(grid, row + 1, col, m, n) + dfs(grid, row, col + 1, m, n);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int area = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    area = dfs(grid, i, j, m, n);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};
