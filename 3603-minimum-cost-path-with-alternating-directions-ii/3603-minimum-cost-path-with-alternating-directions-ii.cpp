class Solution {
public:
long long find(int i,int j,vector<vector<long long>> &dp,vector<vector<int>>& waitCost,int sec){
    if(i==0 && j==0){
        return 1;
    }
    if(i<0 || j<0) return 1e18;
    if(dp[i][j]!=-1) return dp[i][j];
    long long wait=1e18;
    long long l=1e18,r=1e18;
    if(sec>0 &&sec%2){
        wait=find(i,j,dp,waitCost,sec+1)+waitCost[i][j];
    }
    else{
        l=find(i,j-1,dp,waitCost,sec+1)+(i+1)*(j+1);
        r=find(i-1,j,dp,waitCost,sec+1)+(i+1)*(j+1);
    }
    l=min(l,r);
    return dp[i][j]=min(l,wait);

}
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<long long>> dp(m,vector<long long>(n,-1));
        int sec=0;
        long long ans=find(m-1,n-1,dp,waitCost,sec);
        if(ans==1e18) return -1;
        return ans;
    }
};