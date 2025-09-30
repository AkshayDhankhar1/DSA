class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        while(n>1){
            vector<int> nums1(n-1,0);
            for(int i=0;i<n-1;i++){
                nums1[i]=(nums[i]+nums[i+1])%10;
            }
            nums=nums1;
            n--;
        }
        return nums[0];
        
    }
};