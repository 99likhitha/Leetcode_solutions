class Solution {
public:
    int minOperations(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int lb=1,ub=1;
        while(lb*2<n)
        {
            lb*=2;
        }
        ub=lb*2-n;
        lb=n-lb;
        int low=minOperations(lb);
        int high=minOperations(ub);

        return min(low,high) +1;
       
    }
};