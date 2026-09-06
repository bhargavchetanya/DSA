class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<double> prev(m+1,0),curr(m+1,0);
        prev[0]=curr[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                double take=0;
                if(s[i-1]==t[j-1]){
                    take=prev[j-1];
                }
                double nottake=prev[j];
                curr[j]=take+nottake;
            }
            prev=curr;
        }
        return prev[m];
    }
};