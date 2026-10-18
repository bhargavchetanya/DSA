class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double,double>mp;
        long long ans=0;
        int n=rectangles.size();
        for(int i=0;i<n;i++){
            mp[(double)rectangles[i][0]/rectangles[i][1]]++;
        }
        for(auto it:mp){
            if(it.second>1){
                ans+=(it.second*(it.second-1)/2);
            }
        }
        return ans;
    }
};