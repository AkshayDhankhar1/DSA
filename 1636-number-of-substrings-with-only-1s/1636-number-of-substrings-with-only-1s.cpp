class Solution {
public:
    int numSub(string s) {
        long long ans=0;
        long long count=0;
        const long long mod=1000000007;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                count=(count+1)%mod;
                ans=(ans+count)%mod;
            }
            else {
                count=0;
            }
        }
        return ans;
    }
};