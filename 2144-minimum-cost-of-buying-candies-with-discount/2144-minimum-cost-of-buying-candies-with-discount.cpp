class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        sort(cost.begin(), cost.end());
        int mincost=0;
        int i=n-1;
        while(i>=2)
        {
            mincost+=cost[i]+cost[i-1];
            i-=3;
            // i=(i+n)%n;
        }

        while(i>=0)
        {
            mincost+=cost[i];
            i--;
        }
        return mincost;
    }
};
// [1,2,3] 
// [1,2,3,4]

// [2,2,5,6,7,9]