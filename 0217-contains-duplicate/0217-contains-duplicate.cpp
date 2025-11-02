class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n= nums.size();
        unordered_set<int>S;
        for(int num:nums)
        {
            if(S.count(num)) return true;
            S.insert(num);
        }

        return false;
    }
};