class Solution {
public:
    void f(vector<int>&temp,vector<bool>&used,vector<int>& nums,vector<vector<int>>&ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]==true)continue;
            used[i]=true;
            temp.push_back(nums[i]);
            f(temp,used,nums,ans);
            used[i]=false;
            temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>used(n,false);
        f(temp,used,nums,ans);
        return ans;
    }
};