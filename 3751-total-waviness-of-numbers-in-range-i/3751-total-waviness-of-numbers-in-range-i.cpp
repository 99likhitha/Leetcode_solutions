class Solution {
public:
    int wavy(int num)
    {
        int ans=0;
        int last =num%10;
        int newnum=num/10;

        while(newnum>=10)
        {
           int i=newnum%10;
           int left=(newnum/10)%10;
            if( (i>left && i>last) || (i<left && i<last))
            {
                ans+=1;
            }
            last=i;
            newnum/=10;
        }

        return ans;
    }
    int totalWaviness(int num1, int num2) {
        int ans=0;

        for(int i=num1;i<=num2;i++)
        {
            ans+=wavy(i);
        }

        return ans;
    }
};