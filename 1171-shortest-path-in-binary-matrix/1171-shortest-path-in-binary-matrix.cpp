class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        vector<vector<int>>vis(n,vector<int>(n,-1));
        queue<pair<int,int>>q;
        int shortest=INT_MAX;
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        vis[0][0]=1;
        q.push({0,0});

        while(!q.empty())
        {
            auto &p=q.front();
            int x=p.first;
            int y=p.second;
            q.pop();

            if(x==n-1 && y== n-1) return vis[x][y];
            for(int i=0;i<8;i++)
            {
                int newx=x+dir[i][0];
                int newy=y+dir[i][1];
                if(newx>=0 && newx<n && newy>=0 && newy<n && grid[newx][newy]==0 && vis[newx][newy]==-1)
                {
                    vis[newx][newy]=vis[x][y]+1;
                    q.push({newx,newy});
                }
            }
        }
        return -1;

    }
};