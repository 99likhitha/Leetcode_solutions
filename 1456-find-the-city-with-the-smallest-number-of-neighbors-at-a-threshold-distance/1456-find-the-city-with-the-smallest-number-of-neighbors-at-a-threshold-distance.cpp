class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &edge:edges)
        {
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
      
       vector<vector<int>>Neighbours(n);
      for(int i=0;i<n;i++)
      {
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        vector<int>dist(n,INT_MAX);
        dist[i]=0;
        pq.push({0,i});
        while(!pq.empty())
        {
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(d>dist[node]) continue;
           for(auto N:adj[node])
            {
                int neigh=N.first;
                int distance=N.second;
                if(dist[node]!=INT_MAX && distance+d<dist[neigh])
                {
                    dist[neigh]=distance+d;
                    pq.push({distance+d,neigh});
                }
            }
        }

        for(int v=0;v<n;v++)
        {
            if(v!=i && dist[v]<=distanceThreshold)
            {
                Neighbours[i].push_back(v);
            }
        }
      }

        int size=INT_MAX;
        int index=-1;
        for(int i=0;i<Neighbours.size();i++)
        {
         if(Neighbours[i].size()<size || Neighbours[i].size()== size && i>index ) 
         {
            size=Neighbours[i].size();
            index=i;
         }   

        }

        return index;
    }
};