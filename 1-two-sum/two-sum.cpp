class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int num1=nums[i];
            int num2=target-num1;
            if(mp.find(num2)!=mp.end()){
                return {i,mp[num2]};
            }
            else{
                mp[num1]=i;
            }
        }
        return {-1,-1};
    }
};