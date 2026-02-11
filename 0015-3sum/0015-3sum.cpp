class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>> st;
        for(int i=n-1;i>=0;i--){
            int l=0;
            int r=i-1;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]==0){
                    vector<int> temp={nums[l],nums[r],nums[i]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                    l++;
                    r--;
                }
                else if(nums[i]+nums[l]+nums[r]>0){
                    r--;
                }
                else l++;
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};