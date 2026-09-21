class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total=0;
        int currmax=0;
        int maxsum=INT_MIN;

        int currmin=0;
        int minsum=INT_MAX;

        for(int i=0;i<nums.size();i++)
        {
            currmax=max(nums[i],currmax+nums[i]);
            maxsum=max(currmax,maxsum);

            currmin=min(nums[i],currmin+nums[i]);
            minsum=min(minsum,currmin);

            total+=nums[i];
        }
        if(maxsum<0) return maxsum;

        int cirsum=total-minsum;
        return max(maxsum,cirsum);
        
    }
};