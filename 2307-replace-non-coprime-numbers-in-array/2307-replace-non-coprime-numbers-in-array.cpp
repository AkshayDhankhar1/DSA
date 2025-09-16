class Solution {
public:
int copr(int a,int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long> st;
    for (int x : nums) {
        long long curr = x;
        while (!st.empty()) {
            long long g = copr(st.top(), curr);
            if (g == 1) break;
            curr = (st.top() / g) * curr;
            st.pop();
        }
        st.push(curr);
    }
        
        vector<int>ans(st.size());
        for(int i=st.size()-1;i>=0;i-- ){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};