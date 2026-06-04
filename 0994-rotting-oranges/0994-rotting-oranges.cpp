class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    visited[i][j]=true;
                }
            }
        }
        int count=0;
        while(!q.empty()){
            int s=q.size();
            bool exist=false;
            for(int i=0;i<s;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x-1>=0 && !visited[x-1][y] && grid[x-1][y]==1){
                    visited[x-1][y]=true;
                    q.push({x-1,y});
                    exist=true;
                }
                if(x+1<n &&!visited[x+1][y]&& grid[x+1][y]==1){
                    visited[x+1][y]=true;
                    q.push({x+1,y});
                    exist=true;
                }
                if(y-1>=0 &&!visited[x][y-1]&& grid[x][y-1]==1){
                    visited[x][y-1]=true;
                    q.push({x,y-1});
                    exist=true;
                }
                if(y+1<m && !visited[x][y+1]&& grid[x][y+1]==1){
                    visited[x][y+1]=true;
                    q.push({x,y+1});
                    exist=true;
                }
            }
            if(exist)count++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    return -1; 
                }
            }
        }
        return count;
    }
};