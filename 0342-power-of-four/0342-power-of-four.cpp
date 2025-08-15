class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1) return true;
        if(n<=0 || n%2 !=0) return false;
        double ans=log(n)/log(4);
        return (ceil(ans) == floor(ans));
    }
};