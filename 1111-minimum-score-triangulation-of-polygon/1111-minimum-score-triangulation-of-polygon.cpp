class Solution {
public:
    int minScoreTriangulation(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    long tri = 1L * v[i] * v[k] * v[j];
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + (int)tri);
                }
            }
        }
        return dp[0][n - 1];
    }
};