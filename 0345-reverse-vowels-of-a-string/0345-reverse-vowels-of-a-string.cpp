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
        string vowels="";
        for(char c:s)
        {
            if(isvowel(c))
            {
                vowels+=c;
            }
        }
        int i=vowels.length()-1;
        for(int j=0;j<s.length();j++)
        {
            if(isvowel(s[j]))
            {
                s[j]=vowels[i];
                i--;
            }
        }

        return s;
    }
};