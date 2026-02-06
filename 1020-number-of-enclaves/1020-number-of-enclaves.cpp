class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                q.push({i,0});
            }
            if(grid[i][m-1]==1){
                q.push({i,m-1});
            }
            visited[i][0]=true;
            visited[i][m-1]=true;
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==1){
                q.push({0,j});
            }
            if(grid[n-1][j]==1){
                q.push({n-1,j});
            }
            visited[0][j]=true;
            visited[n-1][j]=true;
        }
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x+1<n && !visited[x+1][y] && grid[x+1][y]==1){
                q.push({x+1,y});
                visited[x+1][y]=true;
            }
            if(y+1<m && !visited[x][y+1] && grid[x][y+1]==1){
                q.push({x,y+1});
                visited[x][y+1]=true;
            }
            if(x-1>=0 && !visited[x-1][y] && grid[x-1][y]==1){
                q.push({x-1,y});
                visited[x-1][y]=true;
            }
            if(y-1>=0 && !visited[x][y-1] && grid[x][y-1]==1){
                q.push({x,y-1});
                visited[x][y-1]=true;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 &&!visited[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};