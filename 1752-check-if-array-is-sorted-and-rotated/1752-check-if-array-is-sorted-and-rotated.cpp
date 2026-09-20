class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>nums[(i+1)%nums.size()]) count++;
        }
        return 1>=count;
    }
};



//         int n=nums.size();
//         bool flag=true;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 if(nums[j]<nums[i])
//                 {
//                     return flag=false;
//                 }
//             }
//         }
//         return flag;
//     }
// };