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
    bool find(TreeNode* root, int &k,unordered_map<int,bool>&mp){
        if(mp.find(k-root->val)!=mp.end())return true;
        else mp[root->val]=true;
        if(root->left&&find(root->left,k,mp))return true;
        if(root->right&&find(root->right,k,mp))return true;
        return false;

    }

    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,bool>mp;
        return find(root,k,mp);
    }
};