class Solution {
public:
void find(vector<vector<int>> &ans,int target,vector<int>& candidates,int inx,vector<int>& a){
    if(inx>=candidates.size()){
        if(target==0){
            ans.push_back(a);
        }
        return;
    }
    if(target>=candidates[inx]){
    a.push_back(candidates[inx]);
    find(ans,target-candidates[inx],candidates,inx,a);
    a.pop_back();
    }
    find(ans,target,candidates,inx+1,a);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int inx=0;
        vector<int> a;
        vector<vector<int>> ans;
        find(ans,target,candidates,inx,a);
        return ans;
    }
};