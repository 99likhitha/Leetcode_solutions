class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        if(m==0) return;
        int n=board[0].size();
        if(n==0) return;
        queue<pair<int,int>>q;
        vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};

        auto push=[&](int x,int y)
        {
            if(x<0 || x>=m || y<0 || y>=n) return;
            if(board[x][y]=='O')
            {
                board[x][y]='T';
                q.push({x,y});
            }
        };


        for(int i=0;i<m;i++)
        {
            push(i,0);
            if(n>1) push(i,n-1);
        }
        for(int j=0;j<n;j++)
        {
            push(0,j);
            if(m>1) push(m-1,j);
        }
        
        
        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();

            for(int i=0;i<4;i++)
            {
                int newx=x+directions[i][0];
                int newy=y+directions[i][1];
                push(newx,newy);
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='T') board[i][j]='O';
            }
        }
    }
};