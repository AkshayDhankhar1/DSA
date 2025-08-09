class Solution {
public:
    void find(vector<int>& nums, vector<vector<int>>& ans, vector<int>& arr,
              int index) {

        ans.push_back(arr);

        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1])
                continue;
            arr.push_back(nums[i]);
            find(nums, ans, arr, i + 1);
            arr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(nums.begin(), nums.end());
        find(nums, ans, arr, 0);
        return ans;
    }
};