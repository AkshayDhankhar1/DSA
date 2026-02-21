class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_map<int,int> hash;
        for(int i:  bulbs){
            hash[i]++;
        }
        vector<int> ans;
        for(auto it: hash){
            if(it.second%2==1){
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};