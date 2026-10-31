class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int final_product=1;
        int product=1;
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                final_product=0;
                count++;
            }
            else{
                final_product*=nums[i];
                product*=nums[i];
            }
        }
        vector<int>ans;
        if(count>1){
            for(int i=0;i<n;i++){
                ans.push_back(0);
            }
            return ans;
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                ans.push_back(product);
            }
            else{
                ans.push_back(final_product/nums[i]);
            }
        }
        return ans;
    }
};