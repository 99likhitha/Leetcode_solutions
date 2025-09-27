class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>effort(n,vector<int>(m,INT_MAX));
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        pq.push({0,{0,0}});
        effort[0][0]=0;

        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            int dis=p.first;
            int x=p.second.first;
            int y=p.second.second;
            if(dis>effort[x][y]) continue;
            if(x==n-1 && y==m-1) return dis;
            for(int i=0;i<4;i++)
            {
                int newx=x+dir[i][0];
                int newy=y+dir[i][1];
                if(newx>=0 && newx<n && newy>=0 && newy<m )
                {
                    int diff_effort=abs(heights[x][y]-heights[newx][newy]);
                    int neweffort=max(dis,diff_effort);

                    if(neweffort<effort[newx][newy])
                    {
                        effort[newx][newy]=neweffort;
                        pq.push({neweffort,{newx,newy}});
                    }

                }

            }

        }
        return -1;

    }
};