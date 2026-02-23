class Solution {
public:
    bool hasAllCodes(string s, int k) {
       int count=pow(2,k);
        set<string>set1;
        for(int i=0;i<s.length();i++)
        {
            string ss;
            if(i+k<=s.length())
            {    ss=s.substr(i,k);
            if(set1.find(ss)==set1.end())
            {
                set1.insert(ss);
               
            }
        }
        }
        if (set1.size()==pow(2,k)) return true;
        return false;
    }
};