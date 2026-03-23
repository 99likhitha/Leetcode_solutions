class Solution {
public:
    const int MOD = 1e9+7;
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(2, -1)));
        long long p = grid[0][0];
        dp[0][0][0] = dp[0][0][1] = p;
        for(int j=1; j<n; j++){
            p *= grid[0][j];
            dp[0][j][0] = dp[0][j][1] = p;
        }
        p = grid[0][0];
        for(int i=1; i<m; i++){
            p *= grid[i][0];
            dp[i][0][0] = dp[i][0][1] = p;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                auto top = dp[i-1][j];
                auto left = dp[i][j-1];
                dp[i][j][0] = max(max(1LL*top[0]*grid[i][j], 1LL*left[0]*grid[i][j]), max(1LL*top[1]*grid[i][j], 1LL*left[1]*grid[i][j]));
                dp[i][j][1] = min(min(1LL*top[1]*grid[i][j], 1LL*left[1]*grid[i][j]), min(1LL*top[0]*grid[i][j], 1LL*left[0]*grid[i][j]));
            }
        }
        long long maxProduct = dp[m-1][n-1][0] %MOD;
        return maxProduct<0? -1 : maxProduct;
    }
};