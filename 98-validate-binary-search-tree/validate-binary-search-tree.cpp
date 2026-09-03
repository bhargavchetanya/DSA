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
    bool isValidBST(TreeNode* root) {
        long long p=LLONG_MIN;
        bool flag=true;
        TreeNode* curr=root;
        while(curr){
            if(!curr->left){
                if(p>=curr->val)flag=false;
                p=curr->val;
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right&&prev->right!=curr)prev=prev->right;
                if(prev->right!=curr){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    if(p>=curr->val)flag=false;
                    p=curr->val;
                    curr=curr->right;
                    prev->right=NULL;
                }
            }
        }
        return flag;
    }
};