class Solution {
public:
    int findmax(vector<int> &piles)
    {
        int maxi = INT_MIN;
        for(int x : piles)
        {
            maxi = max(maxi, x);
        }
        return maxi;
    }

    long long calculateTotalHours(vector<int>&piles,int hourly)
    {
        long long totalH = 0;

        for(int i = 0; i < piles.size(); i++)
        {
            totalH += (piles[i] + hourly - 1) / hourly;
        }

        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = findmax(piles);

        while(lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            long long totalH = calculateTotalHours(piles, mid);

            if(totalH <= h)
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        return lo;
    }
};