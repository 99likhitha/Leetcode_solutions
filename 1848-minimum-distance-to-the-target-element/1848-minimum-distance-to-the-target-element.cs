public class Solution {
    public int GetMinDistance(int[] nums, int target, int start) {
        var n=nums.Length;
        int mindist=int.MaxValue;
        for(int i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                mindist=Math.Min(mindist,Math.Abs(i-start));
            }
        }
        return mindist;
    }
}