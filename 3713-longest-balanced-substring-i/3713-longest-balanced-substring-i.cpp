class Solution {
public:
    int longestBalanced(string s) {
        int n=s.length();
        int maxlen=0;
        for(int i=0;i<n;i++)
        {
           
            unordered_map<char,int>mp;
            for(int j=i;j<n;j++)
            {
                if(mp.find(s[j]) != mp.end())
                {
                    mp[s[j]]++;  
                }
                int count=mp[s[j]];
                int flag=true;
                for(auto itr: mp)
                {
                    if(itr.second !=count) flag=false;
                }
                if(flag) maxlen=max(maxlen,j-i+1);
            }
        }

        return maxlen;
    }
};