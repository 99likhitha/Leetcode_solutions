class Solution {
public:
string palindrome(int i,int j,string&s)
{

    while(i>=0 && j<=s.size() && s[i]==s[j])
    {
        i--;
        j++;
    }

    return s.substr(i+1,j-i-1);
}
    string longestPalindrome(string s) {
        int n=s.size();
        string result="";
        for(int i=0;i<n;i++)
        {
            string evenpal=palindrome(i,i+1,s);
            if(evenpal.size()> result.size()) result=evenpal;

            string oddpal=palindrome(i,i,s);
            if(oddpal.size()>result.size()) result=oddpal;
        }

        return result;
    }
};