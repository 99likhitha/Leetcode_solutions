class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        if(n==1) return 1;
        if(n==2) return 2;
        int prev2=1;
        int prev1=2;
        int curr;
        for(int i=3;i<=n;i++)
        {
            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
};