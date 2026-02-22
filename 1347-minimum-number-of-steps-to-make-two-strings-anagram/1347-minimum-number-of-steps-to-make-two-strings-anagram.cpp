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
                int a=it.second-hash2[it.first];
                if(a>0){
                    ans+=a;
                }
            }
            else ans+=it.second;
        }
        return ans;
    }
};