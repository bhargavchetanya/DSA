class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),[](int a,int b){
            return abs(a)>abs(b);
        });
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