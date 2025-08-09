class Solution {
public:
    void find(vector<int>& arr, vector<vector<int>>& ans, int target, int index,
              vector<int>& candidates) {
        if (target == 0) {
            sort(arr.begin(),arr.end());
            ans.push_back(arr);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1])
                continue; // skip duplicates
            if (candidates[i] > target)
                break; // pruning
            arr.push_back(candidates[i]);
            find(arr, ans, target - candidates[i], i + 1, candidates);
            arr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> arr;
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        find(arr, ans, target, 0, candidates);
        return ans;
    }
};
