class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size();
        int n=classroom[0].length();

        vector<vector<int>>id(m,vector<int>(n,-1));

        int sr=0;
        int sc=0;
        int litter=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(classroom[i][j]=='S'){
                    sr=i;
                    sc=j;
                }
                if(classroom[i][j]=='L'){
                    id[i][j]=litter++;
                }
            }
        }

        if(litter==0)return 0;

        int states=1;
        for(int i=0;i<litter;i++)states*=2;

        vector<int>power(litter);
        power[0]=1;

        for(int i=1;i<litter;i++)
            power[i]=power[i-1]*2;

        vector<vector<vector<vector<bool>>>>visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy+1,
                    vector<bool>(states,false)
                )
            )
        );

        queue<tuple<int,int,int,int>>q;

        q.push({sr,sc,energy,0});
        visited[sr][sc][energy][0]=true;

        int vrow[4]={-1,1,0,0};
        int vcol[4]={0,0,-1,1};

        int ans=0;

        while(!q.empty()){
            int size=q.size();

            while(size--){
                auto[row,col,currenr,mask]=q.front();
                q.pop();

                if(mask==states-1)
                    return ans;

                if(currenr==0)
                    continue;

                for(int j=0;j<4;j++){
                    int nr=row+vrow[j];
                    int nc=col+vcol[j];

                    if(nr<0||nr>=m||nc<0||nc>=n)
                        continue;

                    if(classroom[nr][nc]=='X')
                        continue;

                    int newenergy=currenr-1;
                    int newmask=mask;

                    if(classroom[nr][nc]=='R')
                        newenergy=energy;

                    if(classroom[nr][nc]=='L'){
                        int k=id[nr][nc];

                        int value=(mask/power[k])%2;

                        if(value==0)
                            newmask+=power[k];
                    }

                    if(!visited[nr][nc][newenergy][newmask]){
                        visited[nr][nc][newenergy][newmask]=true;

                        q.push({
                            nr,
                            nc,
                            newenergy,
                            newmask
                        });
                    }
                }
            }

            ans++;
        }

        return -1;
    }
};