class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int remainder;
        int dividend;
        int ans=numBottles;;
        while(numBottles>=numExchange)
        {
            dividend=numBottles/numExchange;
            remainder=numBottles%numExchange;
            remainder+=dividend;
            numBottles=remainder;
            ans+=dividend;
        }

        return ans;

    }
};