/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        int level=1;
        int anslevel=1;
        int maxsum=INT_MIN;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int n=q.size();
            int sum=0;
            for(int i=0;i<n;i++)
            {
                TreeNode* a=q.front();
                q.pop();
                sum+=a->val;
                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
            }
            if(sum>maxsum)
            {
                maxsum=sum;
                anslevel=level;
            }
            level++;
        }
        return anslevel;
        
    }
};