class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt=0;
        int l=0;
        int r=0;
        int pmax=0;
        while(r<nums.size()){
            if(nums[r]==0){
                cnt++;
                
            }
            while(cnt>1){
                if(nums[l]==0) cnt--;
                l++;
            }
            pmax=max(pmax,r-l);
            r++;
        }
        return pmax;        
    }
};