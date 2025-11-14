class Solution {
public:
    int maxOperations(string s) {
        int n=s.size();
        int result=0;
        int cars=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                cars++;
            }
            else if( i>0 && s[i-1] =='1')
            {
                result+=cars;
            }
        }

        return result;
    }
};