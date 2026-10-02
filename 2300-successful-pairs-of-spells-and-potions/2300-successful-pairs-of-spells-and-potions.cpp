class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>ans;
        for(int spell:spells)
        {
            int low=0;
            int high=potions.size()-1;
            int first=potions.size();
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                if((long long)spell*potions[mid]>=success)
                {
                    first=mid;
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            ans.push_back(potions.size()-first);
        }
        return ans;
    }
};