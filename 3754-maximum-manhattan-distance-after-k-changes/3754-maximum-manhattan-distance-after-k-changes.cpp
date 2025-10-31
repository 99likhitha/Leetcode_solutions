class Solution {
public:
    int maxDistance(string s, int k) {
       int len=s.length();
        int x=0,y=0;
        int ans=INT_MIN;
        for(int i=0;i<len;i++)
        {
            if (s[i] == 'N') y++;
            else if (s[i]  == 'S') y--;
            else if (s[i]  == 'E') x++;
            else if (s[i]  == 'W') x--;

        int base=abs(x) + abs(y);
        int maxdist=min(base + 2*k, i+1);
        ans=max(ans,maxdist);
        }

        
        return ans;
    }
};