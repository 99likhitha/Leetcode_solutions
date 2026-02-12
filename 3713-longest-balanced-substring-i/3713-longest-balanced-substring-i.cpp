class Solution {
public:
    int longestBalanced(string s) {
        int n=s.length();
        int maxlen=0;
        for(int i=0;i<n;i++)
        { 
            int maxfreq=0;
            unordered_map<char,int>mp;
            for(int j=i;j<n;j++)
            {
                mp[s[j]]++;  
                maxfreq=max(maxfreq,mp[s[j]]);
                
                if(mp.size() * maxfreq == j-i+1)
                {
                 maxlen=max(maxlen,j-i+1);
                }
            }
        }

        return maxlen;
    }
};