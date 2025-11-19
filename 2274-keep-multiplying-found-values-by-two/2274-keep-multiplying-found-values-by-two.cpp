class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int>S;
        for(int num:nums)
        {
            S.insert(num);
        }

        while(1)
        {
            if(S.find(original) == S.end()) return original;
            else
            {
                original*=2;
            }
        }

        return original;
    }
};