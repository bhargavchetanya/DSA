class Solution {
public:
    long long sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;

        for(int k=1;k<=n;k++){
            if(n%k)continue;

            bool ok=true;
            int prev=INT_MIN;

            for(int i=0;i<n&&ok;i+=k){
                int mn=nums[i],mx=nums[i],desc=0;

                for(int j=i;j<i+k;j++){
                    mn=min(mn,nums[j]);
                    mx=max(mx,nums[j]);

                    int nxt=(j+1==i+k)?i:j+1;
                    if(nums[j]>nums[nxt])desc++;
                }

                if(desc>1||mn<prev){
                    ok=false;
                    break;
                }

                prev=mx;
            }

            if(ok)ans+=k;
        }

        return ans;
    }
};