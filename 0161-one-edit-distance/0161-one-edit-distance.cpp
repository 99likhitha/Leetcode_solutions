class Solution {
public:
    bool isOneEditDistance(string s, string t) {       
       int n=s.length();
       int m=t.length();
        if(s==t) return false;
        if(abs(m-n) >1) return false;
        int i=0,j=0;
        int count=0;
        while(i<n && j<m)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                count++;
                if(count>1) return false;
                if(n>m)
                {
                    i++;
                }
                else if(n<m)
                {
                    j++;
                }
                else
                {
                    i++;
                    j++;
                }
            }
        }

        if(i<n || j<m) count++;

        return count==1;
    }

 };