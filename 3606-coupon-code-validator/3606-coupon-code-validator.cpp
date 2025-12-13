#include <cctype>
class Solution {
public:
    bool isAlphanumericString(const std::string& str) {
    return !str.empty() && std::all_of(str.begin(), str.end(),
        [](char c) { return std::isalnum(c) || c == '_'; });
}
    
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        set<string>st;
        st.insert("electronics");
        st.insert("grocery");
        st.insert("pharmacy");
        st.insert("restaurant");
    unordered_map<string, int> order = {
    {"electronics", 0},
    {"grocery", 1},
    {"pharmacy", 2},
    {"restaurant", 3}
};
        vector<pair<string,string>>ans;
        for(int i=0;i<code.size();i++)
        {
          if(isAlphanumericString(code[i]))
          {
              if(st.find(businessLine[i]) !=st.end() && isActive[i])
              {
                  ans.push_back({code[i],businessLine[i]});
              }
          }
        }
       sort(ans.begin(), ans.end(), [&](auto& a, auto& b) {
        if (order[a.second] != order[b.second])
            return order[a.second] < order[b.second];
        return a.first < b.first;
    });
        
        vector<string>res;
        for(auto &p: ans)
            {
                res.push_back(p.first);
            }
        return res;
    }
};