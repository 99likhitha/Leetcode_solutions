class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
        auto push=[&](int x,int y)
        {
            if(x<0 || x>=m || y <0 || y>=n) return;
            if(grid[x][y]==1) 
            {
                grid[x][y]=2;
                q.push({x,y});
            }
        };

        for(int i=0;i<m;i++)
        {
            push(i,0);
            if(n>1) push(i,n-1);
        }

        for(int i=0;i<n;i++)
        {
            push(0,i);
            if(m>1) push(m-1,i);
        }

        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();

            for(int i=0;i<4;i++)
            {
                int newx=x+directions[i][0];
                int newy=y+directions[i][1];
                if(newx>=0 && newx<m && newy>=0 && newy<n && grid[newx][newy]==1)
                {
                    grid[newx][newy]=2;
                    q.push({newx,newy});
                    
                }
                // push({newx,newy});
            }
            
        }
        
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) count++;
            }
        }

        return count;

    }
};