class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j=i+1;j<n;j++){
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l=j+1;
                int h=n-1;
                while(l<h){
                    long long tar=(long long)target-nums[i]-nums[j];
                    if(nums[l]+nums[h]==tar){
                        ans.push_back({nums[i],nums[j],nums[l],nums[h]});
                        l++;
                        h--;
                    while(l<h && nums[l]==nums[l-1])l++;
                    while(l<h && nums[h]==nums[h+1])h--;
                    }
                    else if(nums[l]+nums[h]>tar){
                        h--;
                    }
                    else l++;
                }
            }
        }
        return ans;
    }
};