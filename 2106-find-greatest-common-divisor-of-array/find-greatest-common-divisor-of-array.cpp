class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        int greatest=INT_MIN;
        int smallest=INT_MAX;
        for(int i=0;i<n;i++){
            greatest=max(greatest,nums[i]);
            smallest=min(smallest,nums[i]);
        }
        return gcd(smallest,greatest);
    }
};