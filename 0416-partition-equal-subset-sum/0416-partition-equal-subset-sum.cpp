class Solution {
public:
bool find(int ind,int tar,vector<int>& nums,vector<vector<int>> &dp){
    if(tar==0) return true;
    if(ind==0) return (tar==nums[0]);
    if(dp[ind][tar]!=-1) return dp[ind][tar];
    bool l= find(ind-1,tar,nums,dp);
    bool r=false;
    if(tar>=nums[ind]){
        r=find(ind-1,tar-nums[ind],nums,dp);
    }
    return dp[ind][tar]=l||r;
}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n= nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false ;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return find(n-1,sum/2,nums,dp);
    }
};