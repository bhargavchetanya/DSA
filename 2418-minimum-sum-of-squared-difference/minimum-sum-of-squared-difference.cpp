class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        long long ans=0;
        long long sum=0;
        map<int,long long,greater<int>>mp;
        for(int i=0;i<n;i++){
            int d=abs(nums1[i]-nums2[i]);
            mp[d]++;
        }
        long long k=(long long)k1+(long long)k2;
        while(k){
            int num=mp.begin()->first;
            long long freq=mp.begin()->second;
            if(num==0)break;
            if(freq==0){
                mp.erase(mp.begin());
                continue;
            }
            else{
                if(k>=freq){
                    mp[num]=0;
                    mp[num-1]+=freq;
                    k-=freq;
                }
                else{
                    mp[num]-=k;
                    mp[num-1]+=k;
                    k=0;
                }
            }
        }
        for(auto it:mp){
            long long freq=it.second;
            long long num=it.first;
            ans+=freq*(num*num);
        }
        return ans;
    }
};