class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        if(n==2){
            if(nums[0]>nums[1])return 1;
            else return 0;
        }
        int peak=0;
        int index=0;
        int ans1=INT_MAX;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                peak++;
                index=i;
            }
        }
        if(peak==0)return 0;
        if(peak==1&&nums[0]>=nums[n-1]){
            ans1=min(index+1,n-(index+1)+2);
        }
        peak=0;
        index=0;
        int ans2=INT_MAX;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                peak++;
                index=i+1;
            }
        }
        if(peak==0)return 1;
        if(peak==1&&nums[0]<=nums[n-1]){
            ans2=min(index+1,n-index+1);
        }
        if(ans1==INT_MAX&&ans2==INT_MAX)return -1;
        return min(ans1,ans2);
    }

};