class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<char>>g(m,vector<char>(n,'#'));
        for(int i=0;i<m;i++){
            g[i][0]='.';
        }
        for(int i=0;i<n;i++){
            g[m-1][i]='.';
        }
        vector<string>ans;
        for(int i=0;i<m;i++){
            string temp="";
            for(int j=0;j<n;j++){
                temp.push_back(g[i][j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};