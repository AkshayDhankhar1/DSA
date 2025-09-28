class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
       int maxi=0;
       sort(nums.begin(),nums.end());
       for(int k=nums.size()-1;k>=2;k--){
        int j=k-1;
        int i=j-1;
        if(nums[i]+nums[j]>nums[k]){
                maxi= nums[i]+nums[j]+nums[k];
                break;
        }
       }
       return maxi;

    }
};