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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return root;
        if(root->val==key&&!root->right&&!root->left){
            return NULL;
        }
        else if(root->val==key&&!root->right&&root->left){
            return root->left;
        }
        else if(root->val==key&&!root->left&&root->right){
            return root->right;
        }
        else if(root->val==key&&root->left&&root->right){
            TreeNode* reference=root;
            root=root->right;
            TreeNode* refrence2=root;
            while(root->left){
                root=root->left;
            }
            root->left=reference->left;
            reference->left=NULL;
            reference->right=NULL;
            return refrence2;
            
        }
        if(root->right&&root->val<key){
            root->right=deleteNode(root->right,key);
        }
        if(root->left&&root->val>key){
            root->left=deleteNode(root->left,key);
        }
        return root;
    }
};