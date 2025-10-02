class Disjointset{
    public:
        vector<int>size,parent;
    Disjointset(int n)
    {
        size.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }

    }

    int findparent(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=findparent(parent[node]);
    }

    void unionbysize(int u,int v)
    {
        int ulpu=findparent(u);
        int ulpv=findparent(v);
        if(ulpu==ulpv) return;
        if(size[ulpu]<size[ulpv])
        {
            parent[ulpu]=ulpv;
            size[ulpv]+=size[ulpu];
        }
        else
        {
            parent[ulpv]=ulpu;
            size[ulpu]+=size[ulpv];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjointset ds(n);
        int extraedges=0;
        for(auto edges: connections)
        {
            int u=edges[0];
            int v=edges[1];
            if(ds.findparent(u)==ds.findparent(v))
            {
                extraedges++;
            }
            else
            {
                ds.unionbysize(u,v);
            }
        }


        int connectedcomponents=0;

        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i) connectedcomponents++;
        }

        int ans=connectedcomponents-1;
        if(extraedges>=ans)
        {
            return ans;
        }
        return -1;
    }
};