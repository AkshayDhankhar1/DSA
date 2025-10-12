class Solution {
public:
int find(vector<int>& nums,vector<vector<int>> &dp,int ind,int tar){
    if(ind==0){
        if(tar==0 && nums[0]==0) return 2;
        if(tar==0 || nums[0]==tar) return 1;
        else return 0;
    }
    if(dp[ind][tar]!=-1) return dp[ind][tar];
    int l=find(nums,dp,ind-1,tar);
    int r=0;
    if(tar>=nums[ind]){
        r=find(nums,dp,ind-1,tar-nums[ind]);
    }
    return dp[ind][tar]=l+r;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int x:nums){sum+=x;}
        if(sum < abs(target)||(target+sum)%2!=0 ) return 0;
        vector<vector<int>> dp(n,vector<int>((target+sum)/2 +1,-1));
        return find(nums,dp,n-1,(target+sum)/2);

    }
};