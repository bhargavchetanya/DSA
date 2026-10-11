class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int number=(n-i)*(i+1);
            int valid=(number+1)/2;
            ans+=valid*arr[i];
        }
        return ans;
    }
};