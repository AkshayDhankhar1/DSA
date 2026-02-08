class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int i=0;
        int j=0;
        int n=nums.size();
        for(int x=0;x<n;x++){
            if(nums[x]>nums[i]){
                i=x;
            }
            if(nums[x]<nums[j]){
                j=x;
            }
        }
        int mini=min(i,j);
        int maxi=max(i,j);
        int ans=INT_MAX;
        ans=min(ans,min(n-mini,min(maxi+1,n+mini-maxi+1)));
        return ans;
    }
};