class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }
        vector<int>idx_maxi;
        vector<int>idx_mini;
        for(int i=0;i<n;i++){
            if(nums[i]==maxi)idx_maxi.push_back(i);
            if(nums[i]==mini)idx_mini.push_back(i);
        }
        int ans=INT_MAX;
        if(maxi==mini){
            for(int i=0;i<idx_maxi.size();i++){
                ans=min({i+1,n-i+1,ans});
            }
        }
        else{
            for(int i=0;i<idx_maxi.size();i++){
                for(int j=0;j<idx_mini.size();j++){
                    int index1=min(idx_maxi[i],idx_mini[j]);
                    int index2=max(idx_maxi[i],idx_mini[j]);
                    int m1=INT_MAX;
                    int m2=INT_MAX;
                    int m3=INT_MAX;
                    m1=index2+1;
                    m2=n-index1;
                    m3=1+index1+n-index2;
                    ans=min({ans,m1,m2,m3});
                }
            }
        }
        return ans;
    }
};