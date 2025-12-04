class Solution {
public:
    string toGoatLatin(string sentence) {
        int n=sentence.size();
        stringstream ss(sentence);
        string word;
        vector<string>words;
        while(ss>>word) 
        {
            words.push_back(word);
        }

        vector<string>result;
        unordered_set<char>S={'a','e','i','o','u','A','E','I','O','U'};
        for(int i=0;i<words.size();i++)
        {
            string temp="";
            string w=words[i];
            if(S.count(w[0]))
            {
                temp+=w+"ma";
            }
            else
            {
                temp+=w.substr(1,w.size()) + w[0] + "ma";
            }

            for(int j=0;j<=i;j++)
            {
                temp+="a";
            }

            result.push_back(temp);
        }

        string ans="";
        for(int i=0;i<result.size();i++)
        {
            if(i!=result.size()-1)
            {
                ans+=result[i]+" ";
            }
            else
            {
                ans+=result[i];
            }
        }

        return ans;

        
       
    }
};