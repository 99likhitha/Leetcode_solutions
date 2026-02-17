class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reverse=0,power=31;
        while(n!=0)
        {
            reverse+=(n&1) <<power;
            n=n>>1;
            power--;
        }
        return reverse;
    }
};