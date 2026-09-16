class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size()&&nums[i]<0){
            i++;
        }
        int x=0;
        int temp=k;
        while(i>0&&temp>0){
            nums[x]*=-1;
            i--;
            temp--;
            x++;
        }
        sort(nums.begin(),nums.end());
        if(temp%2==1)nums[0]*=-1;
        int sum=0;
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
        }
        return sum;
    }
};