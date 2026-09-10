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
int ans=0;
    pair<int,int> f(TreeNode*root){
        if(root==NULL)return {0,0};
        int sum=0;
        int count=0;
        pair<int,int> left={0,0};
        left=f(root->left);
        pair<int,int> right={0,0};
        right=f(root->right);
        sum+=root->val+left.first+right.first;
        count=left.second+right.second+1;
        if(sum/count==root->val){
            ans++;
        }
        return {sum,count};
    }
    int averageOfSubtree(TreeNode* root) {
        pair<int,int> x=f(root);
        return ans;
    }
};