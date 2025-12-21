#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(); // Number of rows (strings)
        if (n == 0) return 0;
        int m = strs[0].length(); // Number of columns (length of strings)
        int ans = 0;
        // sorted[i] is true if strs[i] and strs[i + 1] are already in the correct lexicographical order
        vector<bool> sorted(n - 1, false);

        for (int j = 0; j < m; ++j) {
            int i;
            // First pass: Check if keeping the current column violates the order for any unconfirmed pair
            for (i = 0; i + 1 < n; ++i) {
                if (!sorted[i] && strs[i][j] > strs[i + 1][j]) {
                    // Violation found, this column must be deleted
                    ++ans;
                    break;
                }
            }

            // If the column wasn't deleted, update the sorted array
            if (i + 1 == n) {
                for (i = 0; i + 1 < n; ++i) {
                    if (!sorted[i] && strs[i][j] < strs[i + 1][j]) {
                        // This column establishes a strict order for this pair
                        sorted[i] = true;
                    }
                }
            }
        }

        return ans;
    }
};