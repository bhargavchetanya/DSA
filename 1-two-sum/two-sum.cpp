class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[nums[0]]=0;
        for(int i=1;i<n;i++){
            int t=target-nums[i];
            if(mp.find(t)!=mp.end()){
                return {i,mp[t]};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};