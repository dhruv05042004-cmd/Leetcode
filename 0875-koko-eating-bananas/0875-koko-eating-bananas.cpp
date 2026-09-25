class Solution {
public:
    bool canEat(vector<int>& piles,int h,int k)
    {
        long long hours=0;
        for(int pile:piles)
        {
            hours+=(pile+k-1)/k;
        }
        if(hours<=h)return true;
        else return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=0;
        for(int i=0;i<piles.size();i++)
        {
            high=max(high,piles[i]);
        }
        int ans=high;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(canEat(piles,h,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
        
    }
};