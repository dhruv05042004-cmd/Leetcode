class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<k;i++)
        {
            sum+=nums[i];
        }
        int mx=sum;
        int j=k;
        int i=1;
        while(j<n)
        {
            sum+=nums[j]-nums[i-1];
            mx=max(sum,mx);
            i++;
            j++;
        }
        return (double)mx/k;
    }
};