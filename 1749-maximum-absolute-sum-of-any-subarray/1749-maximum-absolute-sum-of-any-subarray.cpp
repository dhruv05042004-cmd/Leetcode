class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxsum=INT_MIN;
        int currmax=0;

        int minsum=INT_MAX;
        int currmin=0;

        int ans=0;

        for(int i=0;i<nums.size();i++)
        {
            currmax=max(nums[i],nums[i]+currmax);
            maxsum=max(maxsum,currmax);

            currmin=min(nums[i],nums[i]+currmin);
            minsum=min(minsum,currmin);
        }
        return max(maxsum,abs(minsum));
        
    }
};