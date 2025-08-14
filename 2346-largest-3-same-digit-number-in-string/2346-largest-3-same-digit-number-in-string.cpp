class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        string ans="";
        string curr="";
        int i=0,j=0;
        while(i<n && j<n)
        {
            if(!curr.empty())
            {
                if(curr.back()!=num[j])
                {
                    curr="";
                    i=j;
                    curr+=num[j];
                    j++;
                }
                else
                {
                    curr+=num[j];
                    j++;
                    if(curr.length()==3) ans=max(ans,curr);
                }
            }
            else
            {
                curr+=num[j];
                j++;
            }
        }

        return ans;
    }
};