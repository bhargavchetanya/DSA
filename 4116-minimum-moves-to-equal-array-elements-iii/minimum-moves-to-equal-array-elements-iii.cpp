class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(maxi<nums[i]){
                int diff=-maxi+nums[i];
                maxi=nums[i];
                ans+=maxi-nums[i];
                ans+=diff*i;
            }
            else ans+=maxi-nums[i];
        }
        return ans;
    }
};