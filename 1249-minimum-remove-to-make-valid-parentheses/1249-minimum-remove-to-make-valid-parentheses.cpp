class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        string ans="";
        int count=0;
        for(char c:s)
        {
            if(c=='(')
            {
                ans+=c;
                count++;
            }
            else if(c==')' && count>0)
            {
                count--;
                ans+=c;
            }
            else if(c !=')')
            {
                ans+=c;
            }
        }

        string result="";
        reverse(ans.begin(),ans.end());
        for(char c:ans)
        {
            if(c=='(' && count>0) // skip it
            {
                count--;
            }
            else
            {
                result+=c;
            }  
        }
        reverse(result.begin(),result.end());
        return result;       
    }
};