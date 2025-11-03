class Solution {
public:
    vector<string>result;

    bool isvalid(string part)
    {
        if(part.size()>1 && part[0]=='0') return false;

        int num=stoi(part);
        return num>=0 && num<=255;
    }
    void backtrackIP(string &s,int i, vector<string>&ans)
    {
        if(ans.size()==4)
        {

            if(i==s.size())
            {
                result.push_back(ans[0]+'.' + ans[1] + '.' + ans[2]+'.' + ans[3]);
            }
            return;
        }


        for(int len=1;len<=3 && i+len<=s.size();len++)
        {
            string part=s.substr(i,len);
            if(isvalid(part))
            {
                ans.push_back(part);
                backtrackIP(s,i+len,ans);
                ans.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        int n=s.size();
        vector<string>ans;
        backtrackIP(s,0,ans);

        return result;
       

    }
};