// alloca
constexpr int maxv = 100001;
struct S {
    int xmax = 0;
    int xmin = maxv;
    int ymax = 0;
    int ymin = maxv;
};

class Solution {
public:
    static int countCoveredBuildings(const int n, const vector<vector<int>>& a) noexcept {
        S* s = static_cast<S*>(alloca((n + 1) * sizeof(S)));
        for (int i = 0; i <= n; ++i) {
            new (&s[i]) S();
        }
        for (const vector<int>& xy : a) {
            const int x = xy[0];
            const int y = xy[1];
            s[y].xmax = max(s[y].xmax, x);
            s[y].xmin = min(s[y].xmin, x);
            s[x].ymax = max(s[x].ymax, y);
            s[x].ymin = min(s[x].ymin, y);
        }
        int count = 0;
        for (const vector<int>& xy : a) {
            const int x = xy[0];
            const int y = xy[1];
            count += x > s[y].xmin & x < s[y].xmax & y > s[x].ymin & y < s[x].ymax;
        }
        return count;
    }
};