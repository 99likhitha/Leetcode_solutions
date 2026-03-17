public class Solution {
    public int LargestSubmatrix(int[][] matrix) {
        int m=matrix.Length;
        int n=matrix[0].Length;

        for(int i=1; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == 1)
                {
                    matrix[i][j] += matrix[i-1][j];
                }
            }
        }

        int ans=0;
        for(int i=0; i<m; i++)
        {
            int[] temp = (int[])matrix[i].Clone();
            Array.Sort(temp);
            Array.Reverse(temp); 

            for(int j=0; j< temp.Length; j++)
            {
                int height = temp[j];
                int width = j+1;
                ans = Math.Max(ans, height * width);
            }
        }

        return ans;
    }
}