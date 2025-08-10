class Solution {
public:
bool check(string s){
    int l=0;
    int r=s.size()-1;
    while(l<=r){
        if(s[l]!=s[r]) return false;
        l++;
        r--;
    }
    return true;
}
void find(string&s,int index,vector<vector<string>>&ans,vector<string>&arr){
    if(index>=s.size()) {
        ans.push_back(arr);
        return;
    }
    for(int i=index;i<s.size();i++){
        string st=s.substr(index,i-index+1);
        if(check(st)){
            arr.push_back(st);
            find(s,i+1,ans,arr);
            arr.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> arr;
        find(s,0,ans,arr);
        return ans;
    }
};