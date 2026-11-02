class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        int j=n-1;
        int ans=0;
        while(i<j){
            ans+=nums[j--]-nums[i++];
        }
        return ans;
    }
};