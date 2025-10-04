class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxarea=0;
        int i=0,j=n-1;
        while(i<j)
        {
           int h=min(height[i],height[j]);
           int width= j-i;
           maxarea=max(maxarea, h*width);
           if(height[i]<height[j]) i++;
           else j--;  
        }
        return maxarea;
    }
};