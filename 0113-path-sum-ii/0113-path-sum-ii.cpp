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
    void psum(TreeNode* root,int target,vector<vector<int>> &ans,vector<int> &v,int &sum)
    {
        v.push_back(root->val);
        sum+=root->val;
        if(root->left==NULL and root->right==NULL)
        {
            if(sum==target)
            {
                ans.push_back(v);
            }
            return ;
        }
        if(root->left!=NULL)
        {
            psum(root->left,target,ans,v,sum);
            v.pop_back();
            sum-=root->left->val;
        }
        if(root->right!=NULL)
        {
            psum(root->right,target,ans,v,sum);
            v.pop_back();
            sum-=root->right->val;
        }
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return {};
        vector<vector<int>> ans;
        vector<int> v; int sum=0;
        psum(root,targetSum,ans,v,sum);
        return ans;
    }
};