class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;
        vector<vector<pair<int,int>>>adj(n);
        for(auto &flight:flights)
        {
            adj[flight[0]].push_back({flight[1],flight[2]});
        }

        vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));
        dist[src][0]=0;
        pq.push({0,{src,0}});
        int count_stops=0;
        while(!pq.empty())
        {
            auto p=pq.top();
            int d=p.first;
            int node=p.second.first;
            int stops=p.second.second;
            pq.pop();
            if(node==dst) return d;
            if(stops==k+1) continue;
            for(auto neigh:adj[node])
            {
                int dstnode=neigh.first;
                int cost=neigh.second;
                int newstop=stops+1, newdist=cost+d;
                if(newdist < dist[dstnode][newstop]) 
                {
                    dist[dstnode][newstop]=newdist;
                    pq.push({newdist,{dstnode,newstop}});
                }
            }
        }

        int ans = INT_MAX;
        for (int s = 0; s <= k + 1; ++s) ans = min(ans, dist[dst][s]);
        return ans == INT_MAX ? -1 : ans;
        
    }

};