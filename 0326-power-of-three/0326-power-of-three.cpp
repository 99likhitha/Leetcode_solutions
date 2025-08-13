class Solution {
public:
    bool isPowerOfThree(int n) {
        // if(n==0) return false;
        // double c=log(n)/log(3);
        

        // return ceil(c)==floor(c);

        long long int temp=1;
        while(temp<n)
        {
            temp+=temp<<1;
        }
        return temp==n;

    }
};