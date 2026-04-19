class Solution {
public:
    bool canTransform(string start, string result) {
        int n=start.size();
        int m=result.size();
        int i=0,j=0;
        while(i < n || j < m)
        {
            while(i<n && start[i]=='X') i++;
            while(j<m && result[j] =='X') j++;

            if(i ==n && j== m ) return true;
            if(i==n || j== m) return false;

            if(start[i] != result[j]) return false;

            if(start[i] == 'L' && i<j) return false;
            if(start[i] =='R' && i>j) return false;

            i++;
            j++;
        }

        return true;
    }
};