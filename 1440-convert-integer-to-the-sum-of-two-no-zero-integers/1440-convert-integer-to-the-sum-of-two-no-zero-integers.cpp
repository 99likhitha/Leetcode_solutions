class Solution {
public:
    bool haszero(int num)
    {
        bool result=false;
        while(num)
        {
            int m=num%10;
            if(m==0) {
                result=true;
                break;
            }
            num/=10;
        }

        return result;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int>ans;
        int left=1,right=n-1;
        for(int i=left;i<=right;i++)
        {
            if(!haszero(left) && !haszero(right) && left+right==n)
            {
                ans.push_back(left);
                ans.push_back(right);
                break;
            }
            else
            {
                left++;
                right--;
            }
        }
        return ans;
    }
};