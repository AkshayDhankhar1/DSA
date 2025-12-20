class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans=0;
        int n= strs.size();
        int k=strs[0].size();
        if(n<=1) return 0;
        for(int j=0;j<k;j++){
            int broke=0;
            for(int i=1;i<n;i++){
                if(strs[i][j]<strs[i-1][j]){
                    broke=1;
                    break;
                }
            }
            if(broke==1) ans++;
        }
        return ans;
    }
};