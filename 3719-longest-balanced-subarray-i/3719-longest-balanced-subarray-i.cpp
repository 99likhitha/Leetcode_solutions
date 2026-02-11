class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int maxlen=0;
        for(int i=0;i<n;i++)
        {
            int even=0,odd=0;
            set<int>s;
            for(int j=i;j<n;j++)
            {
                if(!s.count(nums[j]))
                {
                    if(nums[j]%2==0)
                    {
                        even++;
                    }
                    else
                    {
                        odd++;
                    }
                
                    s.insert(nums[j]);
                }
                if(odd == even) maxlen=max(maxlen,j-i+1);
            }
        }

        return maxlen;
    }
};