class Solution {
public:
int find(vector<int>& coins,vector<vector<int>> &dp,int tar,int ind){
    if(tar==0) return 1;
    if(ind==0){
        if(tar%coins[0]==0) return 1;
        else return 0;
    }
    if(dp[ind][tar]!=-1) return dp[ind][tar];
    int l=find(coins,dp,tar,ind-1);
    int r=0;
    if(tar>=coins[ind]){
        r=find(coins,dp,tar-coins[ind],ind);
    }
    return dp[ind][tar]=l+r;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        if(amount==0) return 1;
        return find(coins,dp,amount,n-1);
    }
};