class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        auto l=lower_bound(nums.begin(),nums.end(),target);
        auto r=upper_bound(nums.begin(),nums.end(),target);
        int left=l-nums.begin();
        int right=r-nums.begin();
        for(int i=left;i<right;i++){
            ans.push_back(i);
        }
        return ans;
    }
};