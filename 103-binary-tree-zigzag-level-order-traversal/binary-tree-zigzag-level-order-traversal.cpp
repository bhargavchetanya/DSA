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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        int count=0;
        while(!q.empty()){
            vector<int>temp;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* current=q.front();
                q.pop();
                temp.push_back(current->val);
                if(current->left)q.push(current->left);
                if(current->right)q.push(current->right);
            }
            if(count%2!=0) reverse(temp.begin(),temp.end());
            count++;
            ans.push_back(temp);
        }
        return ans;
    }
};