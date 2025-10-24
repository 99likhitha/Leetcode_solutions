class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        int num=0,result=0,lastterm=0;
        char op='+';
        for(int i=0;i<n;i++)
        {
            char c=s[i];
            if(isdigit(c))
            {
                num=num*10+ (c-'0');
            }
            if(!isdigit(c) && c!=' ' || i==s.size()-1)
            {
                if(op=='+')
                {
                    result+=lastterm;
                    lastterm = num;
                }
                else if(op=='-')
                {
                   result+=lastterm;
                    lastterm = -num;
                }
                else if(op=='*')
                {
                   lastterm *= num;
                }
                else if(op=='/')
                {
                    lastterm /= num;
                }

                op=c;
                num=0;
            }

        }

        result+=lastterm;
        return result;
    }
};