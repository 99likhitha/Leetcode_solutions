class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int count=0;
        int minele=INT_MAX;
        long long sum=0;
        bool iszero=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]<0)
                {
                    count++;
                }
                minele=min(minele,abs(matrix[i][j]));
                sum+=abs(matrix[i][j]);
                // if(matrix[i][j]==0) iszero=true;
            }
        }

        if(count%2==0) return sum;
        // else 
        // {
        //     if(iszero) return sum;
        // }
        return sum-(2*minele);

    }
};