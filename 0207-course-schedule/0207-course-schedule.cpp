class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);

        for(auto &p : prerequisites)
        {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }


        queue<int>q;
        int count=0;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            count++;

            for(int adjc:adj[node])
            {
                indegree[adjc]--;
                if(indegree[adjc]==0) 
                {
                    q.push(adjc);
                }
            }
        }
        return count==numCourses;
    }
};