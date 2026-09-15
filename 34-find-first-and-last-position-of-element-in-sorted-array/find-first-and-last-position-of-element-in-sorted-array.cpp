class Solution {
public:

    int binary(vector<int> &arr,int n){
        int start=0;
        int end=arr.size()-1;
        int mid;
        while(start<=end){
            mid=start+(end-start)/2;
            if(arr[mid]==n) return mid;
            else if(arr[mid]>n) end=mid-1;
            else if(arr[mid]<n) start=mid+1;
        }
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answer;
        int i=binary(nums,target);
        if(i==-1){
            answer.push_back(-1);
            answer.push_back(-1);
            return answer;
        }
        int start=0;
        int end=i;
        int mid=0;
        int left=i;
        while(start<=end){
            mid=start+(end-start)/2;
            if(nums[mid]==target) {
                left=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        answer.push_back(left);
        start=i;
        end=nums.size()-1;
        mid=0;
        int right=i;
        while(start<=end){
            mid=start+(end-start)/2;
            if(nums[mid]==target) {
                right=mid;
                start=mid+1;
            }
            else end=mid-1;
        }
        answer.push_back(right);
        return answer;

    }
};