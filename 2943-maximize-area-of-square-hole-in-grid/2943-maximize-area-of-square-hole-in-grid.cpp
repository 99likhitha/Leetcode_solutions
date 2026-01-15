class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int hCount = helper(hBars);
        int vCount = helper(vBars);
        int maxLength = 1 + min(hCount, vCount);
        return maxLength * maxLength;
    }
private:
    int helper(vector<int>& bars) {
        int maxCount = 1;
        for (int i = 1, count = 1; i < bars.size(); i++) {
            if ((bars[i - 1] + 1) == bars[i]) maxCount = max(maxCount, ++count);
            else count = 1;
        }
        return maxCount;
    }
};