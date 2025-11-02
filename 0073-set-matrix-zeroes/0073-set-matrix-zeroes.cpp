class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        bool firstcolzero=false;
        for(int row=0;row<n;row++)
        {
            if(matrix[row][0]==0) firstcolzero=true;
            for(int col=1;col<m;col++)
            {
                if(matrix[row][col]==0)
                {
                    matrix[row][0]=0;
                    matrix[0][col]=0;
                }
            }
        }


        for(int row=n-1;row>=0;row--)
        {
            for(int col=m-1;col>=1;col--)
            {
                if(matrix[row][0]==0 || matrix[0][col]==0)
                {
                    matrix[row][col]=0;
                }
            }

            if(firstcolzero)
            {
                matrix[row][0]=0;
            }
        }

    }
};