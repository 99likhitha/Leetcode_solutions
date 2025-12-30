class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        if(n==1) return 1;
        int count=1;
        string compressed="";
        for(int i=1;i<n;i++)
        {
            if(chars[i]==chars[i-1])
            {
                count++;
            }
            else
            {
                compressed+=(chars[i-1]);
                if(count !=1) compressed+=to_string(count);
                count=1;
            }
        }
        
        compressed+=chars[n-1];
        if(count !=1) compressed+=to_string(count);

        chars.clear();
        for(int i=0;i<compressed.size();i++)
        {
            chars.push_back(compressed[i]);
        }
        return chars.size();
    }
};