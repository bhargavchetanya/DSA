class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int absmax=INT_MIN;
        int i=0;
        int n=nums.size();
        int sum=0;
        while(i<n){
            sum+=nums[i];
            absmax=max(absmax,sum);
            if(sum<0)sum=0;
            i++;
        }
        return absmax;
    }
};