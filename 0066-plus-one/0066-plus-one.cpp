class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int>ans;
        int sum= (digits[n-1]+1)%10;
        int carry= (digits[n-1]+1)/10;
        ans.push_back(sum);
      
        for(int i=n-2;i>=0;i--)
        {
            sum=(digits[i]+carry);
            carry=sum/10;
            sum%=10;
            ans.push_back(sum);  
        }

        if(carry ==1 ) ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};