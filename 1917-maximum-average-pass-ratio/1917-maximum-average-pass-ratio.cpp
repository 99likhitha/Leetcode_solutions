class Solution {
public:
    double gain(int num,int denum)
    {
        return (double)(num+1)/(denum+1) - (double)num/denum; 
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        double answer=0.0;
        
        priority_queue<pair<double,int>>q;
        for(int i=0;i<n;i++)
        {
            q.push({gain(classes[i][0],classes[i][1]),i});
        }

        while(extraStudents--)
        {
            auto [f,s]=q.top();
            q.pop();
            classes[s][0]++;
            classes[s][1]++;
            q.push({gain(classes[s][0],classes[s][1]),s});
        }


        for(int i=0;i<n;i++)
        {
            answer+=(double) classes[i][0]/classes[i][1];
        }

        return answer/n;
       
    }
};