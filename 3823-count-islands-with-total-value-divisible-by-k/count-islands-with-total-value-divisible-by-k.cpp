class Solution {
public:
    int m,n;
    
    long long dfs(vector<vector<int>>& grid,vector<vector<bool>>&visited,int i,int j,long long &sum){
        if(grid[i][j]==0)return 0;
        if(visited[i][j])return 0;
        visited[i][j]=true;
        //up
        if(i>0&&grid[i][j]!=0){
            dfs(grid,visited,i-1,j,sum);
        }
        //down
        if(i<m-1&&grid[i][j]!=0){
            dfs(grid,visited,i+1,j,sum);
        }
        //left
        if(j>0&&grid[i][j]!=0){
            dfs(grid,visited,i,j-1,sum);
        }
        //right
        if(j<n-1&&grid[i][j]!=0){
            dfs(grid,visited,i,j+1,sum);
        }
        return sum+=grid[i][j];
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0&&!visited[i][j]){
                    long long sum=0;
                    long long temp=dfs(grid,visited,i,j,sum);
                    if(temp%k==0)ans++;
                }
            }
        }
        return ans;
    }
};