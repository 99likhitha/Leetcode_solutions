class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(), [](const vector<int>a, const vector<int>b)
        {
            if(a[1]==b[1]) return a[0]>b[0];
            else return a[1]<b[1];
        });

        int count=0;
        int b=-1e9,a=-1e9;
        for(auto &interval:intervals)
        {
            int low=interval[0];
            int high=interval[1];
            int inside= ( (b>=low)? 1:0 ) + ((a>=low) ? 1:0);
            if(inside==2)
            {
               continue;
            }
            if(inside==1)
            {
                count++;
                if(a<low)
                {
                    b=a;
                    a=low;
                }
                else
                {
                    b=a;
                    a=high;
                }
            }
            if(inside==0)
            {
                count+=2;
                b=high-1;
                a=high;
            }
        }

        return count;

    }
};