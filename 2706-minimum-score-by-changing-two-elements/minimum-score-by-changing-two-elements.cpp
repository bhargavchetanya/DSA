class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==3)return 0;
        return min({abs(nums[n-1]-nums[2]),abs(nums[n-3]-nums[0]),abs(nums[n-2]-nums[1])});

    }
};