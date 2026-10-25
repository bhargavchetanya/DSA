class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>&visited,int i,int j,int &m,int &n){
        if(visited[i][j])return;
        visited[i][j]=true;
        //up
        if(grid[i][j]==0){
            if(i>0){
            dfs(grid,visited,i-1,j,m,n);
            }
            //left
            if(j>0){
                dfs(grid,visited,i,j-1,m,n);
            }
            //down
            if(i<m-1){
                dfs(grid,visited,i+1,j,m,n);
            }
            //right
            if(j<n-1){
                dfs(grid,visited,i,j+1,m,n);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            if(grid[i][0]==0&&!visited[i][0]){
                dfs(grid,visited,i,0,m,n);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[i][n-1]==0&&!visited[i][n-1]){
                dfs(grid,visited,i,n-1,m,n);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[0][i]==0&&!visited[0][i]){
                dfs(grid,visited,0,i,m,n);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[m-1][i]==0&&!visited[m-1][i]){
                dfs(grid,visited,m-1,i,m,n);
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0&&!visited[i][j]){
                    ans++;
                    dfs(grid,visited,i,j,m,n);
                }
            }
        }
        return ans;
    }
};