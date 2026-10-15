class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            vector<bool>freq(101,false);
            int d=0;
            for(int j=i;j<n;j++){
                if(freq[nums[j]]==false){
                    d++;
                    freq[nums[j]]=true;
                }
                ans+=(d*d);
            }
        }
        return ans;
    }
};