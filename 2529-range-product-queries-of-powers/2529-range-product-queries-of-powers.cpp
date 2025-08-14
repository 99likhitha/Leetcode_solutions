const int MOD=1e9+7;
class Solution {
public:
long long modpow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>answers;
       vector<int> exps;
        for (int bit = 0; bit < 31; ++bit) {
            if ((n >> bit) & 1) exps.push_back(bit);
        }


        int m=exps.size();
        vector<int>pref(m+1,0);
        for(int i=0;i<m;i++)
        {
            pref[i+1]=pref[i]+exps[i];
        }


        for(int q=0;q<queries.size();q++)
        {
            int n1=queries[q][0];
            int n2=queries[q][1];
            int s=pref[n2+1]-pref[n1];
            int val = modpow(2, s, MOD);
            answers.push_back(val);
        }
        return answers;
    }
};