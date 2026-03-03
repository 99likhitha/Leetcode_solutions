class Solution {
public: 
    string invert(string &s )
    {
        string inverted = s ;
        for(char &ch : inverted)
        {
            if(ch == '0')
            {
                ch = '1' ;
            }
            else
            {
                ch = '0' ;
            }
        }
        return inverted ;
    }

    string rev(string &s)
    {
        string reversed = s ;
        reverse(reversed.begin(), reversed.end());
        return reversed ;
    }

public:
    char recursion(int index , int n , string &s , int k )
    {
        if(index == n)
        {
           return s[k-1];
        }

        string inverted = invert(s);
        string rever = rev(inverted);

        s = s + "1" + rever;

       return recursion(index+1 , n , s , k);

    }

public:
    char findKthBit(int n, int k) {
        string s = "0" ;
        return recursion(1, n ,s ,k);

    }
};