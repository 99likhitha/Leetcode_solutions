class Solution {
public:
    bool isvowel(char c)
    {
        if(c=='a' || c=='A' || c=='e' || c=='E' || c=='i'
        || c=='I' || c=='o' || c=='O' || c=='u' || c=='U')
        {
            return true;
        }
        return false;

    }
    string reverseVowels(string s) {
        int n=s.length();
        int i=0,j=n-1;
        while(i<j)
        {
            while(i<n && !isvowel(s[i])) i++;
            while(j>=0 && !isvowel(s[j])) j--;
            if(isvowel(s[i]) && isvowel(s[j]) && i<j)
            {
                swap(s[i],s[j]);
                cout<<s[i]<<","<<s[j]<<endl;
                i++;
                j--;
            }
        }
        return s;
    }
};