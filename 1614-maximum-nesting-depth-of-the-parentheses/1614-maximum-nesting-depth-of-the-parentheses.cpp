class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int p=0;
        for(char x:s)
        {
            if(x=='(') p++;
            else if(x==')') p--;
            ans= max (ans,p);
        }
        return ans;
    }
};