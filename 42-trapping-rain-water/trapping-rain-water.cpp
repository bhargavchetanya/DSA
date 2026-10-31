class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left;
        vector<int>right;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,height[i]);
            left.push_back(maxi);
        }
        maxi=INT_MIN;
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,height[i]);
            right.push_back(maxi);
        }
        reverse(right.begin(),right.end());
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(left[i],right[i])-height[i];
        }
        return ans;
    }
};