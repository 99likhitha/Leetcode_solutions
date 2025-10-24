class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        if(strs.size()==1) 
        {
            ans.push_back(strs);
            return ans;
        }
        
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++)
        {
            int freq[26]={0};
            for(char c:strs[i])
            {
                freq[c-'a']++;
            }

            string key;
            for(int i:freq)
            {
                key+='#';
                key+=to_string(i);
            }

            mp[key].push_back(strs[i]);
            
        }

        for(auto &itr:mp)
        {
            ans.push_back(itr.second);
        }
        return ans;
    }
};