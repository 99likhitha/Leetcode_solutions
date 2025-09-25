class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);

        for(auto &n : prerequisites)
        {
            adj[n[1]].push_back(n[0]);
            indegree[n[0]]++;
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                ans.push_back(i);
            }
        }

        int count=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            count++;
            for(int adjnode:adj[node])
            {
                indegree[adjnode]--;
                if(indegree[adjnode]==0) 
                {
                    q.push(adjnode);
                    ans.push_back(adjnode);
                }
            }   
        }

        if(count !=numCourses) return {};
        return ans;
    }
};