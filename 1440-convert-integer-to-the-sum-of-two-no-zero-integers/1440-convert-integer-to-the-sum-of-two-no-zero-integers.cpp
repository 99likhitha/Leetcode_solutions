#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper to check if a number contains digit '0'
    bool containsZero(int val) {
        while (val > 0) {
            if (val % 10 == 0) return true;
            val /= 10;
        }
        return false;
    }

    vector<int> getNoZeroIntegers(int target) {
        for (int first = 1; first < target; first++) {
            int second = target - first;
            if (!containsZero(first) && !containsZero(second)) {
                return {first, second};
            }
        }
        return {};
    }
};
