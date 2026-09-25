class Solution {
public:
    bool canMake(vector<int>&bloomDay,int m,int k,int day)
    {
        int count=0;
        int b=0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=day)
            {
                count++;
                if(count==k)
                {
                    b++;
                    count=0;
                }
            }
            else count=0;
        }
        return b>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long)m*k>n) return -1;
        int low=1;
        int high=0;
        for(int i=0;i<n;i++)
        {
            high=max(high,bloomDay[i]);
        }
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(canMake(bloomDay,m,k,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
        
    }
};