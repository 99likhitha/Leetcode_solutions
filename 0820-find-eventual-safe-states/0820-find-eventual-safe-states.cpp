class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>outgoing(n);
        vector<vector<int>>rev_adjacency(n);
        queue<int>q;
        vector<int>ans;
    
        for(int i=0;i<n;i++)
        {
            outgoing[i]=graph[i].size();
            for(int node:graph[i])
            {
                rev_adjacency[node].push_back(i);
            }
            if(outgoing[i]==0)  
            {
                q.push(i);
            }
          
        }



        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(int pointed_node:rev_adjacency[node])
            {
                outgoing[pointed_node]--;
                if(outgoing[pointed_node]==0)
                {
                    q.push(pointed_node);
                }
            }
        }

        sort(ans.begin(),ans.end());
       return ans;

    }
};