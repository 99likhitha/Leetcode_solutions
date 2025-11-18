class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        if (n >= 2 && bits[n - 2] == 0) return true;
        while (i < n - 1)
            i += bits[i] + 1;

        return i == n - 1;
    }
};
