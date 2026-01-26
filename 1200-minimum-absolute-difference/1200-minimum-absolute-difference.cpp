class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int mindiff=INT_MAX;
        vector<vector<int>>ans;
        for(int i=1;i<n;i++)
        {
            if(abs(arr[i]-arr[i-1]) < mindiff)
            {
                mindiff=abs(arr[i]-arr[i-1]);
                if(ans.size()>0) ans.clear();
                ans.push_back({arr[i-1],arr[i]});
            }
            else if( abs(arr[i]-arr[i-1]) == mindiff) 
            {
                ans.push_back({arr[i-1],arr[i]});
            }
            else continue;

        }

        return ans;
    }
};