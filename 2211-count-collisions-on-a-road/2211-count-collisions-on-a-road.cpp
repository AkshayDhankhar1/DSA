class Solution {
public:
    int countCollisions(string directions) {
        int ans=0;
        stack<char> st;
        for(int i=0;i<directions.size();i++){
            if(directions[i]=='R' || st.empty()){
                st.push(directions[i]);
            }
            else if(directions[i]=='S'){
                while(!st.empty() &&st.top()=='R' ){
                    st.pop();
                    ans++;
                }
                st.push('S');
            }
            else{
                if(st.top()=='S'){
                    ans++;
                }
                else if(st.top()=='R'){
                    st.pop();
                    ans+=2;
                    while(!st.empty() &&st.top()=='R' ){
                        ans++;
                        st.pop();
                    }
                    st.push('S');
                }

                else st.push('L');

            }
        }
        return ans;
    }
};