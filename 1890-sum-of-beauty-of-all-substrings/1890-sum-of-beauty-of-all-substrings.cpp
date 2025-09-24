class Solution {
public:
int hello(unordered_map<char,int>& hash){
    int maxi=INT_MIN;
    int mini=INT_MAX;
    for(auto it: hash){
        if(it.second<mini) mini=it.second;
        if(it.second>maxi) maxi=it.second;
    }
    return maxi-mini;
}
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int> hash;
            for(int j=i;j<s.size();j++){
                hash[s[j]]++;
                ans+=hello(hash);
            }
        }
        return ans;
    }
};