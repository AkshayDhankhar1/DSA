class Solution {
public:
int find(int m,int n, vector<vector<int>>&dp,int i,int j,vector<vector<int>>& obstacleGrid){
    if(i==m-1 && j==n-1 && obstacleGrid[i][j]==0) return 1;
    if(i==m-1 && j==n-1 && obstacleGrid[i][j]==1) return 0;
    if(i>=m || j>=n) return 0;
    if(obstacleGrid[i][j]==1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int left= find(m,n,dp,i+1,j,obstacleGrid);
    int right= find(m,n,dp,i,j+1,obstacleGrid);
    return dp[i][j]=left+right;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>>dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return find(obstacleGrid.size(),obstacleGrid[0].size(),dp,0,0,obstacleGrid);
        
    }
};