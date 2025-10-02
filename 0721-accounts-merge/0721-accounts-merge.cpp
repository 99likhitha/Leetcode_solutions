class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,vector<string>>graph;
        unordered_map<string,string>emailname;
        unordered_set<string>visited;


        for(auto account:accounts)
        {
            string name=account[0];
            string firstmail=account[1];
            for(int i=1;i<account.size();i++)
            {
                graph[firstmail].push_back(account[i]);
                graph[account[i]].push_back(firstmail);
                emailname[account[i]]=name;
            }
        }


        vector<vector<string>>answer;
        for(auto itr:graph)
        {
            string email=itr.first;
            if(visited.count(email)) continue;
            queue<string>q;
            vector<string>merged;
            q.push(email);
            visited.insert(email);

            while(!q.empty())
            {
                string curr=q.front();
                q.pop();
                merged.push_back(curr);

                for(string &neigh:graph[curr])
                {
                    if(!visited.count(neigh))
                    {
                        visited.insert(neigh);
                        q.push(neigh);
                    }
                }
            }

            sort(merged.begin(),merged.end());
            merged.insert(merged.begin(),emailname[email]);
            answer.push_back(merged);
        }

        return answer;
    }
};