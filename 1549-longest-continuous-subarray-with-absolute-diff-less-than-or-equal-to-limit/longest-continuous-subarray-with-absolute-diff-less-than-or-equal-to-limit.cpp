class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        int ans=0;
        priority_queue<pair<int,int>>mx;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>mn;
        int l=0;
        for(int r=0;r<n;r++){
            mx.push({nums[r],r});
            mn.push({nums[r],r});
            while(mx.top().first-mn.top().first>limit){
                if(mx.top().second<mn.top().second){
                    l=mx.top().second+1;
                }
                else{
                    l=mn.top().second+1;
                }
                while(mx.top().second<l)mx.pop();
                while(mn.top().second<l)mn.pop();
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};