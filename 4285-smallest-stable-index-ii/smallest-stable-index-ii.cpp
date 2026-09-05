class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>smallest(n,0);
        smallest[n-1]=nums[n-1];
        int mini=nums[n-1];
        for(int i=n-2;i>=0;i--){
            mini=min(mini,nums[i]);
            smallest[i]=mini;
        }
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            if(maxi-smallest[i]<=k){
                return i;
            }
        }
        return -1;
    }
};