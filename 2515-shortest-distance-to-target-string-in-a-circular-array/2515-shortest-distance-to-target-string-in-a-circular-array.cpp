class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int mindist=INT_MAX;
        int n=words.size();
        for(int i=0; i < n; i++)
        {
            if( words[i] == target)
            {
                mindist = min( mindist , min(abs(i-startIndex), n-abs(startIndex-i)));
            }
        }

        return (mindist !=INT_MAX) ? mindist : -1 ;
    }
};