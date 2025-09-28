class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        vector<vector<int>>dp (n,vector<int>(n,-1));
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            int miniloop=INT_MAX;
                if(i==0) dp[i][j]=matrix[i][j];
                else {
                    if(j==0) miniloop=dp[i-1][j];
                    else if(j>0){
                        miniloop=min(dp[i-1][j],dp[i-1][j-1]);
                    }
                    if(j<n-1){
                        miniloop=min(dp[i-1][j+1],miniloop);
                    }
                    dp[i][j]=matrix[i][j]+miniloop;
                }
                
            }
        }
        for(int j=0;j<n;j++){
            mini=min(mini,dp[n-1][j]);
        }
        return mini;
        
    }
};