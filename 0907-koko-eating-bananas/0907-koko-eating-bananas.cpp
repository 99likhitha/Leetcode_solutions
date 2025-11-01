class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxele=*max_element(piles.begin(),piles.end());
        int low=1,high=maxele;
        int ans=maxele;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            long long hours=0;

            for(int num:piles)
            {
                hours+=(num+mid-1)/mid;
            }

            if(hours<=h)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }

        return ans;
    
        }
};