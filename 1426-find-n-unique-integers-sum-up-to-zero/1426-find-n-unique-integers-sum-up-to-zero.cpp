class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>answer;
        int start=0;
        if(n%2==0)
        {
            start=1;
        }
        else
        {
            start=0;
        }
        for(int i=start;i<=n/2;i++)
        {
            answer.push_back(-1*i);
        }
        if(n%2==0)
        {
            for(int i=start;i<=n/2;i++)
            {
                answer.push_back(i);
            }
        }
        else
        {
         for(int i=start+1;i<=n/2;i++)
            {
                answer.push_back(i);
            }
        }

        return answer;
    }
};