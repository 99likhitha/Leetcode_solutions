#include <bit>
class Solution {
public:
int countsetbits(int n)
{
    int count=0;
    while(n)
    {
        count+=n&1;
        n>>=1;
    }
    return count;
}
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>v;
        for(int i=0;i<arr.size();i++)
        {
            int count=countsetbits(arr[i]);
            v.push_back({arr[i],count});
        }

        sort(v.begin(),v.end(),[](pair<int,int>&a,pair<int,int>&b){
           if(a.second==b.second)
           {
              return  a.first<b.first;
           }
           return a.second<b.second;

        });

        vector<int>ans;
       for(int i=0;i<v.size();i++)
       {
        ans.push_back(v[i].first);
       }
       return ans;
    }
};