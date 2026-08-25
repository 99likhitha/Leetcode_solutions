class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int prod=1;
        int num=n;
        while(n > 0)
        {
            int digit = n % 10;
            sum+=digit % 10;
            prod*=digit % 10;
            n/=10;
        }

        return num % (sum+prod) == 0;

    }
};