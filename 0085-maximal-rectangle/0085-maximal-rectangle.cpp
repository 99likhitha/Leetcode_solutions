class Solution {
public:
    int largest_hist(vector<int>&V)
    {
        int maxA=0;
        int n=V.size();
        stack<int>st;
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && ( i==n || V[st.top()] >= V[i] ))
            {
                int h=V[st.top()];
                st.pop();
                int width;
                if(st.empty())
                {
                    width=i;
                }
                else
                {
                    width=i-st.top()-1;
                }
                maxA=max(maxA,h*width);
            }
            st.push(i);
        }

        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>height(n,0);
        int maxarea=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1') 
                {
                    height[j]++;
                }
                else
                {
                    height[j]=0;
                }
            }   
            int area=largest_hist(height);
            maxarea=max(maxarea,area);
        }

        return maxarea;
    }
};