struct DSU {
    int n;
    vector<int> parent, size;
    DSU(int N=0): n(N), parent(N), size(N,1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    void unite(int a,int b){
        a = find(a); b = find(b);
        if(a==b) return;
        if(size[a] < size[b]) swap(a,b);
        parent[b] = a;
        size[a] += size[b];
    }
    int compSize(int x){ return size[find(x)]; }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        DSU dsu(n*n);

        auto inside = [&](int r,int c){ return r>=0 && c>=0 && r<n && c<n; };
        auto id = [&](int r,int c){ return r*n + c; };

        // 1) Union adjacent 1s
        const int dr[4] = {-1,0,1,0};
        const int dc[4] = {0,1,0,-1};
        for(int r=0;r<n;++r){
            for(int c=0;c<n;++c){
                if(grid[r][c]==1){
                    for(int k=0;k<4;++k){
                        int nr=r+dr[k], nc=c+dc[k];
                        if(inside(nr,nc) && grid[nr][nc]==1){
                            dsu.unite(id(r,c), id(nr,nc));
                        }
                    }
                }
            }
        }

        // Track current max among existing islands (handles all-1s case)
        int best = 0;
        for(int r=0;r<n;++r){
            for(int c=0;c<n;++c){
                if(grid[r][c]==1){
                    best = max(best, dsu.compSize(id(r,c)));
                }
            }
        }

        // 2) Try flipping each 0 and sum sizes of distinct neighboring components
        for(int r=0;r<n;++r){
            for(int c=0;c<n;++c){
                if(grid[r][c]==0){
                    unordered_set<int> seen; // parent ids
                    int sum = 1; // the flipped cell
                    for(int k=0;k<4;++k){
                        int nr=r+dr[k], nc=c+dc[k];
                        if(inside(nr,nc) && grid[nr][nc]==1){
                            int p = dsu.find(id(nr,nc));
                            if(seen.insert(p).second){ // only add once per component
                                sum += dsu.size[p];
                            }
                        }
                    }
                    best = max(best, sum);
                }
            }
        }

        // If there was at least one 0 considered, best is correct; if all 1s, best was set above
        // Edge case: if grid had no 1s, best becomes 1 by flipping a single cell (handled above loop too)
        if(best==0) return 1; // all zeros grid
        return best;
    }
};
