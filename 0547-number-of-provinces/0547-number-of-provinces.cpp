class Solution {
public:
    int findparent(vector<int>&parent,int x)
    {
        if(parent[x]==x) return x;
        return parent[x]=findparent(parent,parent[x]);
    }

    void Union(vector<int>&parent,int x,int y)
    {
       int parent_x=findparent(parent,x);
       int parent_y=findparent(parent,y);
       if(parent_x !=parent_y) parent[parent_x]=parent_y; 
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>parent(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
       
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<isConnected[0].size();j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    Union(parent,i,j);
                }
                
            }
        }

        for(int i=0;i<n;i++)
        {
            parent[i]=findparent(parent,i);
        }


        set<int>s;
        for(int i=0;i<parent.size();i++)
        {
            s.insert(parent[i]);
        }


        return s.size();


    }
};