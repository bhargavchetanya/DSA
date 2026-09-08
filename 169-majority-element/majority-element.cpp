class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num=0;
        int count=0;
        for(auto x:nums){
            if(count==0)num=x;
            if(num==x)count++;
            else count--;  
        }
        return num;
    }
};