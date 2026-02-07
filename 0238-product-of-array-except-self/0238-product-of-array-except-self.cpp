class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long prod=1;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                cnt++;
            }
            else prod=prod*nums[i];
        }
        vector<int> ans(nums.size(),0);
        if(cnt>1) return ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                ans[i]=prod;
            }
            else if(cnt==0) ans[i]=prod/nums[i];
        }
        return ans;
    }
};