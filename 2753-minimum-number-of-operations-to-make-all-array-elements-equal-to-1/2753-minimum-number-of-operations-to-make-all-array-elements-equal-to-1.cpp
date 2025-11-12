class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int num1 = 0;
        int g = 0;

        // Count number of 1's and compute overall GCD
        for (int x : nums) {
            if (x == 1)
                num1++;
            g = gcd(g, x);
        }

        // Case 1: already contains 1s
        if (num1 > 0)
            return n - num1;

        // Case 2: impossible if overall GCD > 1
        if (g > 1)
            return -1;

        // Case 3: find shortest subarray with GCD = 1
        int min_len = n;
        for (int i = 0; i < n; i++) {
            int curr_g = 0;
            for (int j = i; j < n; j++) {
                curr_g = gcd(curr_g, nums[j]);
                if (curr_g == 1) {
                    min_len = min(min_len, j - i + 1);
                    break;
                }
            }
        }

        // total operations = (min_len - 1) to create 1 + (n - 1) to spread it
        return min_len + n - 2;
    }
};