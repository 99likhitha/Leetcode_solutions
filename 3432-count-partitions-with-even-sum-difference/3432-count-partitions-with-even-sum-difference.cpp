class Solution {
public:
    int countPartitions(vector<int>& A) {
        int leftsum=0;
        int n=A.size();
       for(int num : A)
       {
        leftsum+=num;
       }

        int rightsum=0;
        int count=0;
       for(int i=n-1;i>0;i--)
       {
        rightsum+=A[i];
        leftsum-=A[i];

        if(abs(rightsum-leftsum)%2==0) count++;
       }

       return count;
    }
};