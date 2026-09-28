class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int pre=0;
        int maxalt=0;
        for(int i=0;i<n;i++)
        {
            pre+=gain[i];
            maxalt=max(maxalt,pre);

        }
        return maxalt;
    }
};