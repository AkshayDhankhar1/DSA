class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=healths.size();
        vector<vector<int>> total(n,vector<int>(4));
        for(int i=0;i<n;i++){
            total[i][0]=positions[i];
            total[i][1]=healths[i];
            total[i][3]=i;
            if(directions[i]=='L') total[i][2]=-1;
            else total[i][2]=1;
        }
        sort(total.begin(),total.end());
        stack<int> st;
        for(int i=0;i<n;i++){
            if(total[i][2]==1){
                st.push(i);
            }else{
                while(!st.empty()&& total[st.top()][2]==1){
                    int j=st.top();
                    if(total[i][1]==total[j][1]){
                        total[i][1]=0;
                        st.pop();
                        break;
                    }
                    else if(total[j][1]>total[i][1]){
                        total[i][1]=0;
                        total[j][1]--;
                        break;
                    }
                    else{
                        total[i][1]--;
                        total[j][1]=0;
                        st.pop();
                    }

                }
                if(total[i][1]>0) st.push(i);
            }
            
        }
        vector<pair<int,int>> temp;
            while(!st.empty()){
                temp.push_back({total[st.top()][3],total[st.top()][1]});
                st.pop();
            }
            sort(temp.begin(),temp.end());
            vector<int> ans;
            for(auto it: temp){
                ans.push_back(it.second);
            }
        return ans;
    }
};