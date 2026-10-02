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
    int dfs(TreeNode* root,long long sum,long long currSum)
    {
        if(root==NULL) return 0;
        currSum+=root->val;
        int count=0;
        if(currSum==sum) count++;

        count+=dfs(root->left,sum,currSum);
        count+=dfs(root->right,sum,currSum);
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        int count =0;
        count+=dfs(root,targetSum,0);
        count+=pathSum(root->left,targetSum);
        count+=pathSum(root->right,targetSum);
        return count;
        
    }
};