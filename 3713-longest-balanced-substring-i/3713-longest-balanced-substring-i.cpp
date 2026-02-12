class Solution {
public:
bool istru(unordered_map<char,int> &hash){
    int ans=hash.begin()->second;
    for(auto it: hash){
        if(it.second!=ans) return false;
    }
    return true;
}
    int longestBalanced(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int> hash;
            for(int j=i;j<s.size();j++){
                hash[s[j]]++;
                if(istru(hash)){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};