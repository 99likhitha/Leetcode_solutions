class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n=ages.size();
        sort(ages.begin(),ages.end());
        int left=0,right=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int age=ages[i];
            while(left < n && ages[left]<= (0.5* age + 7))
            {
                left++;
            }
            while(right<n && ages[right]<=age)
            {
                right++;
            }

            ans+=max(0,right-left-1);
        }

        return ans;
    }
};