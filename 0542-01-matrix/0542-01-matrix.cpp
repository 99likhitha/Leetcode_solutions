class Solution {
public:
   
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>answer(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;
       
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    answer[i][j]=0;
                    q.push({i,j});
                }
            }
        }

       vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
       while(!q.empty())
       {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            int newx=x+directions[i][0];
            int newy=y+directions[i][1];

            if(newx<0 || newx>=m || newy< 0 || newy>=n) continue;
            if(answer[newx][newy] >answer[x][y]+1)
            {
                answer[newx][newy]=answer[x][y]+1;
                q.push({newx,newy});
            }
        }

       }
       return answer;
    }
};