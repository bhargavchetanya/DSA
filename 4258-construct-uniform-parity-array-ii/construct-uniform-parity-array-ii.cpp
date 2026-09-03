class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int o=0,e=0;
        int smallest=INT_MAX;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0)e++;
            else o++;
            smallest=min(smallest,nums1[i]);
        }
        if(smallest%2==0){
            if(o==0)return true;
        }
        else return true;
        return false;
    }
};