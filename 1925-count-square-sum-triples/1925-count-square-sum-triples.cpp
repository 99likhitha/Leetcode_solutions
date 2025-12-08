class Solution {
public:
    int countTriples(int n) {
        int answer=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double root=sqrt(i*i + j*j);
                if(root <= n  && ceil(root) == floor(root)) answer++;
            }
        }

        return 2*answer;
    }
};