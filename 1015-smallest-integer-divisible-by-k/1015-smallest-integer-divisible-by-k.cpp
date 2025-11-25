class Solution {
public:
const int MOD=1e9;
    int smallestRepunitDivByK(int k) {
        if(k%2==0 || k%5==0 || k%10==0) return -1;
        unordered_map<int,bool>mp;
        int rem=0;
        for(int length=1;length<=k;length++)
        {
            rem= (rem*10 +1)%k;
            if(rem %k ==0) return length;
            if(mp.find(rem) !=mp.end()) return -1;
            mp[rem]=true;
        }
        
       return -1;
    }
};