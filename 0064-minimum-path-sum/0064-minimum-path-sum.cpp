class Solution {
public:
int find(int i,int j, int m,int n,vector<vector<int>> &dp,vector<vector<int>>& grid){
    if(i==m-1&&j==n-1) return grid[i][j];
    if(i>=m || j>=n) return INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    int left= find(i+1,j,m,n,dp,grid);
    int right= find(i,j+1,m,n,dp,grid);
    return dp[i][j]=min(left,right)+grid[i][j];
}
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return find(0,0,grid.size(),grid[0].size(),dp,grid);
        
    }
};