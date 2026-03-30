class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<int,int> even;
        unordered_map<int,int> odd;

        int n = s1.size();
        for(int i = 0; i < n; i++){
            if(i % 2 == 0) 
                even[s1[i] - 'a']++; 
            else 
                odd[s1[i] - 'a']++; 
        }

        for(int i = 0; i < n; i++){
            if(i % 2 == 0) 
                even[s2[i] - 'a']--; 
            else 
                odd[s2[i] - 'a']--;
        }

        for(auto pair : even){
            if(pair.second != 0) 
                return false;
        }

        for(auto pair : odd){
            if(pair.second != 0) 
                return false;
        }

        return true;
    }
};