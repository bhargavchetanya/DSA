class Solution {
public:
    int f(int i,int j,int &m,int &n,string &s,string &p,vector<vector<int>>&dp){
        if(i==n&&j==m)return 1;
        if(i==n){
            while(j<m&&p[j]=='*')j++;
            if(j==m)return 1;
            return 0;
        }
        if(j==m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==p[j]||p[j]=='?') return dp[i][j]=f(i+1,j+1,m,n,s,p,dp);
        if(p[j]=='*')return dp[i][j]=f(i+1,j+1,m,n,s,p,dp)||f(i+1,j,m,n,s,p,dp)||f(i,j+1,m,n,s,p,dp);
        return 0;

    }

    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int s1=f(0,0,m,n,s,p,dp);
        if(s1==1)return true;
        return false;
    }
};