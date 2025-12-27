class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        string lastword="";
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]== ' '  && lastword !="") break;
            if(isalpha(s[i]))
            {
                lastword+=s[i];
            }
            
        }

        return lastword.size();
    }
};