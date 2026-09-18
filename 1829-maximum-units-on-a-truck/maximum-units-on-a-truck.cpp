class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>a,vector<int>b){
            return a[1]>b[1];
        });
        int ans=0;
        int i=0;
        while(truckSize>0&&i<boxTypes.size()){
            if(truckSize>=boxTypes[i][0]){
                ans+=(boxTypes[i][1]*boxTypes[i][0]);
                truckSize-=boxTypes[i][0];
            }
            else{
                ans+=(truckSize*boxTypes[i][1]);
                truckSize=0; 
            }
            i++;
        }
        return ans;
    }
};