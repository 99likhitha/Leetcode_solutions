class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int>freq;
        int count=1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==s[i-1])
            {
                count++;
            }
            else
            {
                freq.push_back(count);
                count=1;
            }
        }
        freq.push_back(count);

        int ans=0;
        for(int i=1;i<freq.size();i++)
        {
            ans+=min(freq[i-1],freq[i]);
        }

        return ans;

    }
};