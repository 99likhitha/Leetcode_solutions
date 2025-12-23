class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        string pal="";
        for(int i=0;i<n;i++)
        {
            if(s[i]!=' ' && isalnum(s[i]))
            {
                pal+= tolower(s[i]);
            }
        }

        string rev=pal;
        reverse(pal.begin(),pal.end());
        return (rev==pal);
    }
};