class Solution {
public:

    int getsum(int n)
    {
        int sum=0;
        while(n>0)
        {
            int d=n%10;
            sum+=(d*d);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int>S;
        // int num=getsum(n);
        while(n!=1)
        {
            if(S.find(n) == S.end()) 
            {
                S.insert(n);
                n=getsum(n);
            }
            else return false;

        }

        return n==1;

        // int slow=n,fast=getsum(n);
        // while(fast !=1 && slow !=fast)
        // {
        //     slow=getsum(slow);
        //     fast=getsum(getsum(fast));
        // }

        // return fast ==1;
        
    }
};