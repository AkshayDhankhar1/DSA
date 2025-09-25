class Solution {
public:
int find(int i,int j,vector<vector<int>>&triangle,vector<vector<int>> &dp){
    if(i==0 && j==0) return triangle[0][0];
    if(j<0 || j>i) return INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    int left= find(i-1,j,triangle,dp);
    int right= find(i-1,j-1,triangle,dp);
    return dp[i][j]=min(left,right)+triangle[i][j];
}
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),-1));
        int mini=INT_MAX;
        for(int b=0;b<triangle[triangle.size()-1].size();b++){
            int t= find(triangle.size()-1,b,triangle,dp);
            mini=min(mini,t);}
            return mini;
        
    }
};