class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0;
        int r=n-1;
        int sum=INT_MIN;
        while(l<r){
            sum=max(nums[l]+nums[r],sum);
            l++;
            r--;
        }
        return sum;
    }
};