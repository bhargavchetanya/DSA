class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int ans=n;
        vector<int>smallest(n,-1);
        stack<int>st;
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            while(nums[i]<st.top()){
                st.pop();
            }
            if(st.top()==-1){
                st.push(nums[i]);
            }
            smallest[i]=st.top();
        }
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            if(maxi-smallest[i]<=k){
                ans=i;
                break;
            }
        }
        if(ans==n)return -1;
        return ans;
    }
};