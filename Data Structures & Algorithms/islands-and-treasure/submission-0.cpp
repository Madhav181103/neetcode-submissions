class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        // Push all treasure cells
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0)
                    q.push({i, j});
            }
        }

        vector<pair<int,int>> dir = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(auto [dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;

                if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                // Visit only unprocessed land
                if(grid[nr][nc] != INT_MAX)
                    continue;

                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
};