class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> hash1,hash2;
        for(char c: s){
            hash1[c]++;
        }
        for(char c: t){
            hash2[c]++;
        }
        int ans=0;
        for(auto it : hash1){
            if(hash2.count(it.first)){
                ans+=abs(it.second-hash2[it.first]);
            }
            else ans+=it.second;
        }
        for(auto it : hash2){
            if(hash1.find(it.first)==hash1.end()){
                ans+=abs(it.second);
            }
        }
        return ans;
    }
};