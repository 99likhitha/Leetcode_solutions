class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        int diff=0;
        int i=0;
        int j=0;
        while(i<n1&&j<n2){
            if(diff==2)return false;
            if(s[i]==t[j]){
                 i++;
                 j++;
            }
           while((i<n1&&j<n2)&&s[i]!=t[j])
           if(n1==n2&&j+1<n2&&i+1<n1&&s[i+1]==t[j+1]){
            diff++;
            i++;
            j++;
           }
           else if(j+1<n2&&s[i]==t[j+1]){
            diff++;
            j++;
            break;
           }
           else if(i+1<n1&&s[i+1]==t[j]){
            diff++;
            i++;
            break;
           }
           else{
            diff++;
            i++;
            j++;
           }
        }
        while(i<n1){
            diff++;
            i++;
        }
    while(j<n2){
            diff++;
            j++;
        }
        cout<<diff<<"is the diff:"<<endl;
         if(abs(n1-n2)==1&&diff==0||diff==1)return true;//insertion, deletion
         else if(n1-n2==0&&diff==1)return true;//replace
         return false;
    }
   
};