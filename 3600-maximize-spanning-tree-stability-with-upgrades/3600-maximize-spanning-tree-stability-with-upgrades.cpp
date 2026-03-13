#define MOD 1000000007
class Solution {
public:
    int find(int v, std::vector<int>& parent) {
        if (parent[v] == v) {
            return v;
        }
        parent[v] = find(parent[v], parent);
        return parent[v];
    }

    bool unionSets(int a, int b, std::vector<int>& parent, std::vector<int>& size) {
        a = find(a, parent);
        b = find(b, parent);
        if (a != b) {
            if (size[a] < size[b]) {
                std::swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
            return true;
        }
        return false;
    }

    int maxStability(int n, std::vector<std::vector<int>>& edges, int k) {
        std::vector<int> parent(n);
        std::vector<int> size(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        int comp = n;
        int res = INT_MAX;
        std::vector<int> opt;

        for (int idx = 0; idx < edges.size(); ++idx) {
            auto edge = edges[idx];
            if (edge[3] == 1) {
                if (unionSets(edge[0], edge[1], parent, size)) {
                    comp--;
                    res = std::min(res, edge[2]);
                } else {
                    return -1;
                }
            }
        }

        if (comp == 1) {
            return res;
        }

        for (int idx = 0; idx < edges.size(); ++idx) {
            if (edges[idx][3] == 0) {
                opt.push_back(idx);
            }
        }

        std::sort(opt.begin(), opt.end(), [&](int a, int b) {
            return edges[a][2] > edges[b][2];
        });

        std::vector<int> stab;

        for (int idx : opt) {
            auto edge = edges[idx];
            if (unionSets(edge[0], edge[1], parent, size)) {
                comp--;
                stab.push_back(edge[2]);
                if (comp == 1) {
                    break;
                }
            }
        }

        if (comp > 1) {
            return -1;
        }

        for (int i = 1; i <= std::min((int)stab.size(), k); ++i) {
            stab[stab.size() - i] *= 2;
        }

        return std::min(res, *std::min_element(stab.begin(), stab.end()));
    }
};