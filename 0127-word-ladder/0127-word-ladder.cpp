class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> st(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        while(!q.empty()){
            int step=q.front().second;
            string s=q.front().first;
            q.pop();
            if(s==endWord) return step;
            string init= s;
            for(int i=0;i<s.size();i++){
                for(char ch='a';ch<='z';ch++){
                    s[i]=ch;
                    if(st.find(s)!=st.end()){
                        q.push({s,step+1});
                        st.erase(s);
                    }
                }
                s=init;
            }
        }
        return 0;
    }
};