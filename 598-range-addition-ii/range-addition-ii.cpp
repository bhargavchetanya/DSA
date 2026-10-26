class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.size()==0)return m*n;
        int x=ops.size();
        int a=INT_MAX;
        int b=INT_MAX;
        for(int i=0;i<x;i++){
            a=min(a,ops[i][0]);
            b=min(b,ops[i][1]);
        }
        if(a==0&&b==0)return 1;
        else if(a==0&&b!=0)return b;
        else if(a!=0&&b==0)return a;
        return a*b;
    }
};