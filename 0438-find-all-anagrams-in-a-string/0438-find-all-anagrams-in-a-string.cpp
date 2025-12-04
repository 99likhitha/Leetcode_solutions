class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    int n=s.size();
    int m=p.size();
    if(n<m) return {};
    vector<int>freqs(26,0),freqp(26,0);
    vector<int>ans;
    for(char c:p)
    {
        freqp[c-'a']++;
    }


    for(int i=0;i<m;i++)
    {
        freqs[s[i]-'a']++;
    }

    if(freqp == freqs)  ans.push_back(0);

    for(int i=m;i<n;i++)
    {
        freqs[s[i]-'a']++;
        freqs[s[i-m] - 'a']--;

        if(freqs == freqp) ans.push_back(i-m +1);
    }

    return ans;

    }
};