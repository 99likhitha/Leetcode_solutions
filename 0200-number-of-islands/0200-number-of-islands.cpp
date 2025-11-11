class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
         int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int islands = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    bfs(grid, visited, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;

        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int newX = x + dx, newY = y + dy;
                if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
                    grid[newX][newY] == '1' && !visited[newX][newY]) {
                    
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
    }
};