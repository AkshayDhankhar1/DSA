class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        map<map<char,int>,vector<string>> hash;
        for(int i=0;i<n;i++){
            map<char,int> mpp;
            for(int j=0;j<strs[i].size();j++){
                mpp[strs[i][j]]++;
            }
            hash[mpp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it: hash){
            ans.push_back(it.second);
        }
        return ans;

    }
};