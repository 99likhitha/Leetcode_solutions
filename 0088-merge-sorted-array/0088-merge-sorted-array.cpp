class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        while(i<m && j<n)
        {
            if(nums1[i]<=nums2[j])
            {
                i++;
            }
            else if(nums1[i]>nums2[j])
            {
                swap(nums1[i],nums2[j]);
                i++;

                int temp=nums2[j];
                int k=j+1;
                while(k<n && nums2[k]<temp)
                {
                    nums2[k-1]=nums2[k];
                    k++;
                }
                nums2[k-1]=temp;
            }
        }

        while(j<n)
        {
            nums1[i++]=nums2[j++];
        }       
    }
};