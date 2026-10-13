class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0)nums[i]*=-1;
        }
        sort(nums.begin(),nums.end(),greater<>());
        int left=0;
        int right=n-1;
        long long ans=0;
        while(left<=right){
            ans+=(nums[left]*nums[left]);
            if(left!=right)ans-=(nums[right]*nums[right]);
            left++;
            right--;
        }
        return ans;
    }
};