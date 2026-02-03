class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        bool inc0 = false, dec = false, inc1 = false;

        int i = 1;
        while (i < n && nums[i] > nums[i - 1]) {
            inc0 = true;
            i++;
        }
        while (i < n && nums[i] < nums[i - 1]) {
            dec = true;
            i++;
        }
        while (i < n && nums[i] > nums[i - 1]) {
            inc1 = true;
            i++;
        }

        if (inc0 && dec && inc1 && i == n) {
            return true;
        }
        return false;
    }
};