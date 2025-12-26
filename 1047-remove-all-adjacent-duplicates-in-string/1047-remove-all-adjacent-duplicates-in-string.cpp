class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.length();
        stack<char>st;
        int i=0;
        while(i<n)
        {
            if(!st.empty())
            {
                if(st.top() !=s[i]) st.push(s[i]);
                else
                {
                    st.pop();
                }
            }
            else st.push(s[i]);
            i++;
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};