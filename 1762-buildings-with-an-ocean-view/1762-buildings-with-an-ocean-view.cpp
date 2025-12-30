class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n=heights.size();
        vector<int>ans;
        // ans.push_back(n-1);
        // priority_queue<int>pq;
        // pq.push(heights[n-1]);
        int maxheight=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(maxheight<heights[i])
            {
                ans.push_back(i);
                maxheight=heights[i];
            }
            
        }

         reverse(ans.begin(),ans.end());
         return ans;
    }
};