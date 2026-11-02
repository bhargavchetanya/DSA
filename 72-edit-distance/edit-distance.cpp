class Solution {
public:
    int lcs(int i,int j,string &word1,string &word2,int &m,int &n,vector<vector<int>> &dp){
        if(j<0){
            return i+1;
        }
        if(i<0){
            return j+1;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j]=lcs(i-1,j-1,word1,word2,m,n,dp);
        }
        else{
            int del=1+lcs(i-1,j,word1,word2,m,n,dp);
            int insert=1+(lcs(i,j-1,word1,word2,m,n,dp));
            int replace=1+lcs(i-1,j-1,word1,word2,m,n,dp);
            return dp[i][j]=min({del,insert,replace});
        }
    }

    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int s=lcs(n-1,m-1,word1,word2,m,n,dp);
        return s;
    }
};