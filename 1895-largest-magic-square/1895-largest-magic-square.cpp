
class Solution {
    using ll = long long;
    bool check(int i, int j, int sz, vector<vector<int>>& g, vector<vector<ll>>& row, vector<vector<ll>>&  col) {
        // sum1 contains sum of diagonal 1
        ll sum1 = 0;
        for(int k=0; k<sz; k++) sum1 += g[i+k][j+k];

        // sum2 contains sum of diagonal 2
        ll sum2 = 0;
        for(int k=0; k<sz; k++) sum2 += g[i+k][j + sz - 1 -k];
        if(sum2 != sum1) return false;
        
        // check every row sum
        for(int k=i; k<i+sz; k++) {
            ll sum = row[k][j+sz-1];
            if(j > 0) sum -= row[k][j-1];
            if(sum != sum1) return false;
        }

        // check every col sum
        for(int k=j; k<j+sz; k++) {
            ll sum = col[i+sz-1][k];
            if(i>0) sum -= col[i-1][k];
            if(sum != sum1) return false;
        }

        return true;

    }


public:
    int largestMagicSquare(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        vector<vector<ll>> row(m, vector<ll>(n, 0));
        vector<vector<ll>> col(m, vector<ll>(n, 0));

        for(int i=0; i<m; i++) {
            ll sum = 0;
            for(int j=0; j<n; j++) {
                sum += g[i][j];
                row[i][j] = sum;
            }
        }

        for(int j=0; j<n; j++) {
            ll sum = 0;
            for(int i=0; i<m; i++) {
                sum += g[i][j];
                col[i][j] = sum;
            }
        }

        int size = 1;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                for(int sz = 1; i + sz <= m && j + sz <= n; sz++) {
                    if(check(i, j, sz, g, row, col)) size = max(size, sz);
                }
            }
        }
        return size ;
    }
};