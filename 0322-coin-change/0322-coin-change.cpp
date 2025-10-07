class Solution {
public:
int find(int tar,int ind,vector<vector<int>> &dp,vector<int>& coins){
    if(ind==0){
        if(tar%coins[0]==0) return tar/coins[0];
        else return 1e9 ;
    }
    if(dp[ind][tar]!=-1) return dp[ind][tar];
    int l=find(tar,ind-1,dp,coins);
    int r=1e9;
    if(tar>=coins[ind]){
    r=find(tar-coins[ind],ind,dp,coins)+1;
    }
    return dp[ind][tar]=min(l,r);

}
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int n= coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans= find(amount,n-1,dp,coins);
        if(ans>=1e9) return -1;
        return ans;
    }
};