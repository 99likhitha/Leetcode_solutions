class Solution {
public:
    bool judgeCircle(string moves) {
        int up=0,right=0;
        int n=moves.size();
        for(int i=0;i<n;i++)
        {
            if(moves[i]=='U')
            {
                up++;
            }
            else if(moves[i]=='D')
            {
                up--;
            }
            else if(moves[i]=='R')
            {
                right++;
            }
            else
            {
                right--;
            }
        }

        return (up==0 && right ==0);
    }
};
