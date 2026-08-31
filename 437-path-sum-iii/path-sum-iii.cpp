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
    void f(TreeNode* root, int &targetSum,vector<int>&arr,int &count){
        if(!root)return;
        arr.push_back(root->val);
        f(root->left,targetSum,arr,count);
        f(root->right,targetSum,arr,count);
        long long sum=0;
        for(int i=arr.size()-1;i>=0;i--){
            sum+=arr[i];
            if(sum==targetSum){
                count++;
            }
        }
        arr.pop_back();
    }

    int pathSum(TreeNode* root, int targetSum) {
        vector<int>arr;
        int count=0;
        f(root,targetSum,arr,count);
        return count;
    }
};