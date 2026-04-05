class Solution {
public:
    bool judgeCircle(string moves) {
        int n=moves.size();
        int x=0,y=0;
        for(int i=0;i<n;i++)
        {
            if(moves[i]=='U')
            {
                    y=y-1;
            }
            if(moves[i]=='D')
            {
                y=y+1;
            }
            if(moves[i]=='L')
            {
                x=x-1;
            }
            if(moves[i]=='R')
            {
                x=x+1;
            }
        }

        return (x==0 && y==0);
    }
};