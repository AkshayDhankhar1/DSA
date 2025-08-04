class Solution {
public:
void subs(int index,vector<vector<int>> &answer,vector<int>&ans,vector<int>& nums){
    if(index>=nums.size()){
        answer.push_back(ans);
        return ;
    }
    ans.push_back(nums[index]);
    subs(index+1,answer,ans,nums);
    ans.pop_back();
    subs(index+1,answer,ans,nums);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>answer;
        vector<int>ans;
        subs(0,answer,ans,nums);
        return answer;
    }
};
