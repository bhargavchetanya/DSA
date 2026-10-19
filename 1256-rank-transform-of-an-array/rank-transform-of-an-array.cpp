class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>temp=arr;
        vector<int>ans;
        sort(temp.begin(),temp.end());
        temp.erase(unique(temp.begin(),temp.end()),temp.end());
        for(int i=0;i<n;i++){
            int x=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            x++;
            ans.push_back(x);
        }
        return ans;
    }
};