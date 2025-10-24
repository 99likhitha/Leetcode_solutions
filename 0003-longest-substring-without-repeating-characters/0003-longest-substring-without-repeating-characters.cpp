class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxlen=0;
        if(s.size()==0) return 0;
        unordered_map<char,int>mp;
        int i=0,j=0;
        while(i<n && j<n)
        {
            if(mp.find(s[j])!=mp.end() && mp[s[j]] >=i)
            {
               i=mp[s[j]]+1;
            }
            mp[s[j]]=j;
            maxlen=max(maxlen,j-i+1);
            j++;
        }

        return maxlen;
    }
};