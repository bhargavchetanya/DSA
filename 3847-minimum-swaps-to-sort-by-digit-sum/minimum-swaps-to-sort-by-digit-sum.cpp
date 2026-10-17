class Solution {
public:
    int f(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        vector<pair<int,int>>temp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=f(nums[i]);
            temp.push_back({x,i});
        }
        sort(temp.begin(),temp.end(),[&](const auto a,const auto b){
            if(a.first!=b.first)return a.first<b.first;
            return nums[a.second]<nums[b.second];
        });
        int ans=0;
        int i=0;
        while(i<n){
            if(temp[i].second==i){
                i++;
            }
            else{
                ans++;
                swap(temp[i],temp[temp[i].second]);
            }
        }
        return ans;
    }
};