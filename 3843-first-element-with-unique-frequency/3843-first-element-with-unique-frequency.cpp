class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> hash;
        unordered_map<int,vector<int>> ans;
        for(int i: nums){
            hash[i]++;
        }
        for(auto it: hash){
            ans[it.second].push_back(it.first);
        }
        for(int i: nums){
            if(ans[hash[i]].size()==1) return i;
        }
        return -1;

    }
};