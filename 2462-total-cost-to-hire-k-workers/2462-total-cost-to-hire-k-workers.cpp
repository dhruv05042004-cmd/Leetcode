class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>> leftpq;
        priority_queue<int,vector<int>,greater<int>> rightpq;

        int left=0;
        int right=costs.size()-1;

        for(int i=0;i<candidates && left<=right;i++)
        {
            leftpq.push(costs[left]);
            left++;
        }
        for(int i=0;i<candidates && left<=right;i++)
        {
            rightpq.push(costs[right]);
            right--;
        }

        long long ans=0;
        while(k>0)
        {
            if(rightpq.empty()|| (!leftpq.empty()&&leftpq.top()<=rightpq.top()))
            {
                ans+=leftpq.top();
                leftpq.pop();

                if(left<=right)
                {
                    leftpq.push(costs[left]);
                    left++;
                }
            }
            else
            {
                ans+=rightpq.top();
                rightpq.pop();
                if(left<=right)
                {
                    rightpq.push(costs[right]);
                    right--;
                }
            }
            k--;
        }
        return ans;
    }
};