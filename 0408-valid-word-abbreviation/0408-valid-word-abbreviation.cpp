class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int n=word.length();
        int m=abbr.length();
        if(word==abbr) return true;
        int i=0,j=0;
        string num="";
        while(i<n && j<m)
        {
            if(isalpha(abbr[j]))
            {
                num="";
                if(abbr[j]==word[i])
                {
                    i++;
                    j++;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                while(j<m && !isalpha(abbr[j]) )
                {
                    if(num=="" && abbr[j]=='0') return false;
                    num+=abbr[j];    
                    j++;
                } 
                i+=stoi(num);
            }

        }
        return (i==n && j==m);

    }
};