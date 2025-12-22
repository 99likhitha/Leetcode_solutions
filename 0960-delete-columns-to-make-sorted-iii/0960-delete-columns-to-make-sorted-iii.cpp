class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<int> dp(m, 1); // max length ending at column j

        for (int j = 1; j < m; j++) {
            for (int k = 0; k < j; k++) {
                bool can = true;
                for (int i = 0; i < n; i++) {
                    if (strs[i][j] < strs[i][k]) {
                        can = false;
                        break;
                    }
                }
                if(can)  dp[j] = max(dp[j], dp[k] + 1);  
            }
        }
        int maxKeep = 0;
        for (int len : dp) maxKeep = max(maxKeep, len);

        return m - maxKeep;
    }
};