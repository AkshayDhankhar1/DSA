class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visi(n,vector<bool>(m,false));
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    visi[i][j]=true;
                }
            }
        }
        int cnt=0;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(mat[x][y]==1){
                    ans[x][y]=cnt;
                }
                if(x+1<n && !visi[x+1][y]){
                    q.push({x+1,y});
                    visi[x+1][y]=true;
                }
                if(y+1<m &&!visi[x][y+1]){
                    q.push({x,y+1});
                    visi[x][y+1]=true;
                }
                if(x-1>=0 && !visi[x-1][y]){
                    q.push({x-1,y});
                    visi[x-1][y]=true;
                }
                if(y-1>=0 && !visi[x][y-1]){
                    q.push({x,y-1});
                    visi[x][y-1]=true;
                }
            }
            cnt++;
        }
        return ans;
    }
};