class Solution {
public:
const int MOD=1000000007;
    int numberOfWays(int n, int x) {
      vector<int>dp(n+1,0);
      vector<long long>powers;
      for(int i=1;;i++)
      {
        long long p=pow(i,x);
        if(p>n) break;
        powers.push_back(p);
      }


      dp[0]=1;
      
      for(int i=0;i<powers.size();i++)
      {
        for(int s=n;s>=powers[i];s--)
        {
            dp[s]+=dp[s-powers[i]];
            if(dp[s]>MOD) dp[s]-=MOD;
        }
      }

    return dp[n];

    }
};