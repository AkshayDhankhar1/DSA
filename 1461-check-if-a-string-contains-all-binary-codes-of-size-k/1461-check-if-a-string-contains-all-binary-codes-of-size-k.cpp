class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        if(k>s.size()) return false;
        for(int i=0;i<s.size()-k+1;i++){
            string t=s.substr(i,k);
            st.insert(t);
        }
        int n=st.size();
        int j=1;
        for(int i=0;i<k;i++){
            j*=2;
        }
        return (j==n);
    }
};