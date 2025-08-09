class Solution {
public:
string chara(char digit){
    string st;
    char start='a';
    int bef=0;
    int i=digit-'0';
    for(int j=2;j<i;j++){
        if(j==7 || j==9){
            bef+=4;
        }
        else {
            bef+=3;
        }
    }
    int cur=0;
    if(i==7 || i==9){
        cur=4;
    }
    else cur=3;
    for(int k=0;k<cur;k++){
        st.push_back(start+bef+k);
    }
    return st;
    }
void find(vector<string>&ans,string &str,int i,string &digits){
    if(str.size()==digits.size()){
        ans.push_back(str);
        return;
    }
    string st=chara(digits[i]);
    for(int index=0;index<st.size();index++){
        str.push_back(st[index]);
        find(ans,str,i+1,digits);
        str.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string str="";
        if(digits.empty()) return ans;
        find(ans,str,0,digits);
        return ans;
    }
};