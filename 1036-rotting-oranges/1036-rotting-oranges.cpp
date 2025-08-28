class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        queue<pair<int,int>>q;
        int count=0;
        int fresh=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }

        int minutes=0;
        while(!q.empty() && fresh>0)
        {
            int size=q.size();
            while(size--)
            {
            auto p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
            for(int i=0;i<4;i++)
                {
                    int ni=dx[i]+x;
                    int nj=dy[i]+y;
                    if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==1)
                    {
                        grid[ni][nj]=2;
                        q.push({ni,nj});
                        fresh--;
                    }    
                }
            }
             minutes++;
        }

        return fresh==0?minutes:-1;
        
    }
};