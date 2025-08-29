class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n=image.size();
        int m=image[0].size();
        int originalcolor=image[sr][sc];

        if(originalcolor==color)
        {
            return image;
        }
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<pair<int, int>> q;
    q.push({sr, sc});
    image[sr][sc] = color;
     while(!q.empty())
        {
            pair<int,int>temp=q.front();
            int x=temp.first;
            int y=temp.second;
            q.pop();

            for(auto itr:directions)
            {
               int newx=x+itr.first;
               int newy=y+itr.second;

                if(newx>=0 && newx<n && newy>=0 && newy<m && image[newx][newy]==originalcolor )
                {
                    image[newx][newy]=color;
                    q.push({newx,newy});
                }
            }
        }

        return image;
    }

};