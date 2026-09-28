class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int n=nums.size();
        int zerocnt=0;
        int ans=0;
        for(int right=0;right<n;right++)
        {
            if(nums[right]==0){
                zerocnt++;
            }
            while(zerocnt>k)
            {
                if(nums[left]==0){
                    zerocnt--;
                }
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
        
    }
};