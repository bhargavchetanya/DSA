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
    int kthSmallest(TreeNode* root, int k) {
        long long p=LLONG_MIN;
        int ans=0;
        int n;
        TreeNode* curr=root;
        while(curr){
            if(!curr->left){
                n=curr->val;
                k--;
                if(k==0)ans=n;
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
                    n=curr->val;
                    k--;
                    if(k==0)ans=n;
                    curr=curr->right;
                    prev->right=NULL;
                }
            }
        }
        return ans;
    }
};