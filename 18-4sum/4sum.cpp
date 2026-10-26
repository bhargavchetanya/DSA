class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.rbegin(),nums.rend());
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int t=target;
            if(i>0&&nums[i]==nums[i-1])continue;
            int a=nums[i];
            t-=a;
            for(int j=i+1;j<n-2;j++){
                long long t2=t;
                if(j>i+1&&nums[j]==nums[j-1]){
                    continue;
                }
                int b=nums[j];
                t2-=b;
                int k=j+1;
                int l=n-1;
                while(k<l){
                    if(nums[k]+nums[l]==t2){
                    vector<int>temp={a,b,nums[k],nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<n-1&&nums[k]==nums[k-1])k++;
                    while(l>j+1&&nums[l]==nums[l+1])l--;
                    }
                    else if(nums[k]+nums[l]>t2)k++;
                    else l--;
                }
            }
        }
        return ans;
    }
};