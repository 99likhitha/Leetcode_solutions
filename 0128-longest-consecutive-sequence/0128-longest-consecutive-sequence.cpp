class Solution {
public:
    int longestConsecutive(const vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>S;
        if(n==0) return 0;
        for(int num:nums)
        {
            S.insert(num);
        }
        
        int count=1;
        int maxlen=1;
        for(int num:S)
        {
            if(S.find(num-1)==S.end())
            {
                count=1;
                int val=num;
                while(S.find(val+1)!=S.end())
                {
                    count++;
                    val+=1;
                }
                maxlen=max(maxlen,count);
            }
        }

        return maxlen;
       
    }
};