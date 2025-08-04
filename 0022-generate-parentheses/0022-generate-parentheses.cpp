class Solution {
public:
void find(vector<string> &ans,int n,int l,int r,string s){
    if(s.size()>=2*n){
        ans.push_back(s);
        return;
    }
    if(l<n){
        find(ans,n,l+1,r,s+'(');
    }
    if(r<l){
        find(ans,n,l,r+1,s+')');
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        find(ans,n,0,0,"");
        return ans;
    }
};