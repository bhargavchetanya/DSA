class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        bool flag=false;
        int k=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]!=temp[i]){
                k&=(nums[i]&temp[i]);
                flag=true;
            }
        }
        if(flag)return k;
        return 0;
    }
};