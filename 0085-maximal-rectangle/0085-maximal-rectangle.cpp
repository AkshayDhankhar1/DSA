class Solution {
public:
vector<int> ngee(vector<int>&rows){
    stack<int> st;
    vector<int> ans(rows.size());
    for(int i=rows.size()-1;i>=0;i--){
        while(!st.empty()&&rows[st.top()]>rows[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=rows.size();
        }
        else{
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int> pgee(vector<int>&rows){
    stack<int> st;
    vector<int> ans(rows.size());
    for(int i=0;i<rows.size();i++){
        while(!st.empty()&&rows[st.top()]>=rows[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxi=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> rows(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0')rows[j]=0;
                else rows[j]+=1;
            }
            vector<int> nse=ngee(rows);
            vector<int> psee=pgee(rows);
            for(int k=0;k<m;k++){
                maxi=max(maxi,(nse[k] - psee[k] - 1)*rows[k]);
            }
        }
        return maxi;
    }
};