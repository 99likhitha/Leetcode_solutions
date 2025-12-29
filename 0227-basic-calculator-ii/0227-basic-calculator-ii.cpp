class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        int num=0,result=0,lasterm=0;
        char op='+';
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                num=num*10+(s[i]-'0');
            }
            if(  (!isdigit(s[i])  && s[i] !=' ' )|| i==s.size()-1)
            {
                if(op=='+')
                {
                    result+=lasterm;
                    lasterm=num;
                }
                else if(op=='-')
                {
                    result+=lasterm;
                    lasterm=-num;
                }
                else if(op=='*')
                {
                    lasterm*=num;
                }
                else if(op=='/')
                {
                    lasterm /= num;
                }
                op=s[i];
                num=0;
                
            }
            
        }
        result+=lasterm;
        return result;
    }
};