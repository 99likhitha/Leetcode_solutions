class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>S(nums.begin(),nums.end());
        while(S.count(original))
        {
            original*=2;
        }

        return original;
    }
};