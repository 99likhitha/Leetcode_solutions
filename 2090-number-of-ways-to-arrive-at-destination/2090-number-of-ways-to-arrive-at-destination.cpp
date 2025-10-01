class Solution {
public:
const int MOD=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto road:roads)
        {
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});       
        }
        vector<long long>dist(n,LLONG_MAX);
        vector<int>ways(n,0);
        priority_queue<pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>>pq;
        ways[0]=1;
        dist[0]=0;
        pq.push({0,0});

        while(!pq.empty())
        {
            long long time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(time>dist[node]) continue;

            for(auto &neigh: adj[node])
            {
                int neigh_node=neigh.first;
                int time_taken=neigh.second;
                long long newtime=(long long)time_taken+time;
                if( newtime <dist[neigh_node])
                {
                    dist[neigh_node]= newtime;
                    ways[neigh_node]=ways[node];
                    pq.push({ newtime , neigh_node});
                }
                else if( newtime ==dist[neigh_node])
                {
            ways[neigh_node]= (int)(( (long long)ways[neigh_node] + ways[node]) %MOD);
                }
            }
        }

      return ways[n-1];

    }
};