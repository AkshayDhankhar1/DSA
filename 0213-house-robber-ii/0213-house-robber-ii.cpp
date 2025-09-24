class Solution {
public:
int f(int ind,vector<int>& nums,vector<int>& dp){
    if(ind==0) return nums[ind];
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int left=f(ind-2,nums,dp)+nums[ind];
    int right=f(ind-1,nums,dp);
    return dp[ind]=max(left,right);
}
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> dp1(nums.size(),-1);
        int a= nums.back();
        nums.pop_back();
        int l=f(nums.size()-1,nums,dp1);
        nums.push_back(a);
        nums.erase(nums.begin());
        vector<int> dp2(nums.size(),-1);
        int r=f(nums.size()-1,nums,dp2);
        return max(l,r);
       
    }
};