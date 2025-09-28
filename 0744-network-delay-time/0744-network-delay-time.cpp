class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &time:times)
        {
            adj[time[0]].push_back({time[1],time[2]});
        }
        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int>mintimes(n+1,INT_MAX);

        mintimes[k]=0;
        pq.push({0,k});
        while(!pq.empty())
        {
            auto p=pq.top();
            int time=p.first;
            int node=p.second;
            pq.pop();

            if(time>mintimes[node]) continue;

            for(auto neigh:adj[node])
            {
                int newnode=neigh.first;
                int timerequired=neigh.second;
                if(time+timerequired<mintimes[newnode])
                {
                    mintimes[newnode]=time+timerequired;
                    pq.push({time+timerequired, newnode});
                }
            }
        }

        int max_time=*max_element(mintimes.begin()+1,mintimes.end());
        return max_time==INT_MAX ? -1: max_time;

    }
};