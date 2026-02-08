class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> hash;
        for(char c: s){
            hash[c]++;
        }
        vector<pair<int,char>> nums;
        for(auto it: hash){
            nums.push_back({it.second,it.first});
        }
        sort(nums.begin(),nums.end());
        vector<bool> grab(s.size(),false);
        int ans=0;
        for(int i=0;i<nums.size();i++){
            while(nums[i].first>=1 && grab[nums[i].first] == true){
                ans++;
                nums[i].first--;
            }
            if(nums[i].first!=0){
                grab[nums[i].first]=true;
            }
        }
        return ans;

    }
};