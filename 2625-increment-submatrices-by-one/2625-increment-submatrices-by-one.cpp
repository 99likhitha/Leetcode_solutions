class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        int m=queries.size();
        vector<vector<int>>matrix(n,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            int row1=queries[i][0];
            int row2=queries[i][2];
            int col1=queries[i][1];
            int col2=queries[i][3];
            for(int j=row1;j<=row2;j++)
            {
                for(int k=col1;k<=col2;k++)
                {
                    matrix[j][k]+=1;
                }
            }
        }

        return matrix;
    }
};