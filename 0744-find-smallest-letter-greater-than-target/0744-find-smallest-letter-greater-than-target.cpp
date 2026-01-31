class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        if(letters[n-1]<=target) return letters[0];
        int left=0,right=n-1;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(letters[mid]>target)
            {
                right=mid;
            }
            else
            {
                left=mid+1;
            }
        }

        return letters[right];
    }
};