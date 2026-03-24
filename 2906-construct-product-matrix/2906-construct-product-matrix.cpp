class Solution {
public:
int mod=12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int zeros=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<long long>>pre(n,vector<long long>(m,0));
        vector<vector<long long>>suff(n,vector<long long>(m,0));
        long long prod=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pre[i][j]=(prod)%mod;
                prod = (prod * grid[i][j]) % mod;
            }
        }
        prod=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                suff[i][j]=(prod)%mod;
                prod = (prod * grid[i][j]) % mod;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=(pre[i][j]*suff[i][j])%mod;
            }
        }
        return ans;
    }
};