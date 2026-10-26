class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long l=n*n;
        long long ans=0;
        vector<bool>row(n,false);
        vector<bool>col(n,false);
        int nrow=0;
        int ncol=0;
        int x=queries.size();
        for(int i=x-1;i>=0;i--){
            if(l==0)break;
            int type=queries[i][0];
            int line=queries[i][1];
            int val=queries[i][2];
            int overlap=0;
            if(type==0&&!row[line]){
                overlap=ncol;
                ans+=(n-overlap)*val;
                row[line]=true;
                nrow++;
                l-=(n-overlap);
            }
            else if(type==1&&!col[line]){
                overlap=nrow;
                ans+=(n-overlap)*val;
                col[line]=true;
                ncol++;
                l-=(n-overlap);
            }
        }
        return ans;
    }
};