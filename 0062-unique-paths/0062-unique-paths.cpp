class Solution {
public:
int find(int i,int m,int j,int n, vector<vector<int>> &dp){
    if(i==m-1&&j==n-1) return 1;
    if(i>=m || j>=n ) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int left= find(i+1,m,j,n,dp);
    int right= find(i,m,j+1,n,dp);
    return dp[i][j]=left+right;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return find(0,m,0,n,dp);
        
    }
};